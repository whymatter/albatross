import subprocess

import cv2
import numpy as np

import intrinsic_matrix
from manual_chessboard_selector import ManualChessboardSelector

# Input chessboard layout
PATTERN_SIZE = (9, 6)
SQUARE_SIZE_MM = 30

# For calibration
TERM = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_COUNT, 30, 0.01)

# Usability controls
HIST_EQ = False
CHESSBOARD_DETECTION = True
ENABLE_DEBUG = False

# For re-projection
BIG_PATTERN = (20, 19)
BIG_PATTERN_SQUARE_SIZE_MM = 100
USE_DISTORTION = False


# The blue end is always in the white corner, the red one in the dark corner

def set_v4l2_prop(name, value):
    bash_command = 'v4l2-ctl --set-ctrl=%s=%s' % (name, value)
    result = subprocess.check_call(bash_command.split())
    print('set_v4l2_prop %s=%s > %s' % (name, value, result))


def change_resolution(cap, res_w, res_h):
    if cap is not None:
        cap.release()
    cap = cv2.VideoCapture(0)
    cap.set(cv2.CAP_PROP_FRAME_WIDTH, res_w)
    cap.set(cv2.CAP_PROP_FRAME_HEIGHT, res_h)
    return cap


def project_easy(world_points, r, t, resolution, use_distortion=True):
    dist_coeffs = intrinsic_matrix.get_distortion_coefficients() if use_distortion else np.zeros((5,), dtype=np.float32)
    return cv2.projectPoints(world_points, r, t,
                             cameraMatrix=intrinsic_matrix.get_intrinsic_matrix(resolution), distCoeffs=dist_coeffs)


def main():
    global PATTERN_SIZE

    global HIST_EQ
    global CHESSBOARD_DETECTION
    global ENABLE_DEBUG

    global BIG_PATTERN
    global BIG_PATTERN_SQUARE_SIZE_MM

    res_w = 1280
    res_h = 720

    manual_zoomer = ManualChessboardSelector((res_w, res_h))

    # start and configure cam
    cap = None
    cap = change_resolution(cap, res_w, res_h)

    # set properties using v4l2
    set_v4l2_prop('focus_auto', 0)
    set_v4l2_prop('focus_absolute', 0)

    # create window
    cv2.namedWindow('cam_image')
    cv2.namedWindow('detection_image')
    cv2.namedWindow('reprojected_image')

    corners = None
    frame_id = -1
    object_points = np.zeros((PATTERN_SIZE[0] * PATTERN_SIZE[1], 3), dtype=np.float32)
    object_points[:, :2] = np.mgrid[0:PATTERN_SIZE[0], PATTERN_SIZE[1] - 1:-1:-1].T.reshape(-1, 2) * SQUARE_SIZE_MM

    while True:
        img_read, cam_image = cap.read()
        if not img_read:
            print('Failed to read image from capture device')
            break

        detection_image = cv2.cvtColor(cam_image, cv2.COLOR_BGR2GRAY)

        # most of the time equalizeHist
        # (which is also configured to be used by the default flags of findChessboardCorners)
        # does not work well in certain lighting situations
        if HIST_EQ:
            detection_image = cv2.equalizeHist(detection_image)

        # chessboard
        cam_detections_image = cam_image.copy()
        if CHESSBOARD_DETECTION:
            frame_id = (frame_id + 1) % 2
            if frame_id == 0:
                # the defaults for flags do not work for me since i have issues with the light of the picture
                corners_found, image_corners = cv2.findChessboardCorners(detection_image, PATTERN_SIZE,
                                                                         flags=cv2.CALIB_CB_FAST_CHECK)
                if ENABLE_DEBUG:
                    print('found corners: %s' % corners_found)

                if corners_found:
                    cv2.cornerSubPix(detection_image, image_corners, (2, 2), (-1, -1), TERM)

                    if corners is None:
                        # for the first loop
                        corners = image_corners
                    else:
                        # generate a weighted average
                        corners = np.array([corners, image_corners])  # concat last and current
                        corners = np.average(corners, axis=0, weights=(.9, .1)).astype(np.float32)

            if corners is not None:
                cv2.drawChessboardCorners(cam_detections_image, PATTERN_SIZE, corners, True)
                cv2.drawChessboardCorners(detection_image, PATTERN_SIZE, corners, True)
        else:
            corners = manual_zoomer.zooming(cam_image, corners)

        cv2.imshow('cam_image', cam_detections_image)
        cv2.imshow('detection_image', detection_image)

        key = cv2.waitKey(10)
        if key == ord('s'):
            res_w, res_h = 1280, 720
            cap = change_resolution(cap, res_w, res_h)
            manual_zoomer.resolution = (res_w, res_h)
        elif key == ord('b'):
            res_w, res_h = 1280 // 2, 720 // 2
            cap = change_resolution(cap, res_w, res_h)
            manual_zoomer.resolution = (res_w, res_h)
        elif key == ord('h'):
            HIST_EQ = not HIST_EQ
        elif key == ord('d'):
            ENABLE_DEBUG = not ENABLE_DEBUG
        elif key == ord('f'):
            CHESSBOARD_DETECTION = not CHESSBOARD_DETECTION
            corners = None
        elif key == ord('r'):
            corners = None
        elif key == ord('q'):
            break  # exit
        elif key == ord('c'):
            if corners is None:
                print('first you have to capture image points')
                continue

            print('Extrinsic Matrix:')

            if ENABLE_DEBUG:
                print('  object points:')
                print(repr(object_points))
                print('  image points:')
                print(repr(corners))

            dist_coeffs = intrinsic_matrix.get_distortion_coefficients() if USE_DISTORTION else np.zeros((5,),
                                                                                                         dtype=np.float32)
            extrinsic_found, rvec, tvec = cv2.solvePnP(
                object_points, corners,
                cameraMatrix=intrinsic_matrix.get_intrinsic_matrix((res_w, res_h)),
                distCoeffs=dist_coeffs,
                useExtrinsicGuess=False, flags=cv2.SOLVEPNP_ITERATIVE)

            if not extrinsic_found:
                print('failed to compute extrinsic matrix')
                continue

            print('  Transform Vector:')
            print(repr(tvec))
            print('  Rotation Vector:')
            print(repr(rvec))

            object_points_big = np.zeros((BIG_PATTERN[0] * BIG_PATTERN[1], 3), dtype=np.float32)
            object_points_big[:, :2] = np.mgrid[0:BIG_PATTERN[0], 0:BIG_PATTERN[1]].T.reshape(-1,
                                                                                              2) * BIG_PATTERN_SQUARE_SIZE_MM

            big_reprojected_points, _ = project_easy(object_points_big, rvec, tvec, (res_w, res_h), USE_DISTORTION)

            if big_reprojected_points is not None:
                reprojected_image = cam_image.copy()

                # draw settings
                red = (0, 0, 255)
                green = (0, 255, 0)
                blue = (255, 0, 0)
                orange = (0, 255, 255)
                font = cv2.FONT_HERSHEY_SIMPLEX

                # grid
                origin = (-300, -60, 0)  # world origin (mm)
                cell_size = 30  # cell size (mm)
                grid_dimension = (30, 30)  # number of cells

                grid_size = (cell_size * grid_dimension[0], cell_size * grid_dimension[1])

                for x in range(origin[0], origin[0] + grid_size[0], cell_size):
                    p = np.array([[x, origin[1], 0],
                                  [x, origin[1] + grid_size[1], 0]],
                                 dtype=np.float32)
                    image_points, _ = project_easy(p, rvec, tvec, (res_w, res_h), USE_DISTORTION)
                    image_points = image_points.reshape(-1, 2)
                    cv2.line(reprojected_image, tuple(image_points[0]), tuple(image_points[1]), orange, 1, cv2.LINE_AA)

                for y in range(origin[1], origin[1] + grid_size[1], cell_size):
                    p = np.array([[origin[0], y, 0],
                                  [origin[0] + grid_size[0], y, 0]],
                                 dtype=np.float32)
                    image_points, _ = project_easy(p, rvec, tvec, (res_w, res_h), USE_DISTORTION)
                    image_points = image_points.reshape(-1, 2)
                    cv2.line(reprojected_image, tuple(image_points[0]), tuple(image_points[1]), orange, 1, cv2.LINE_AA)

                # draw coordinate system
                world_coord_points = np.array([[0, 0, 0], [200, 0, 0], [0, 200, 0], [0, 0, 200]], dtype=np.float32)
                image_coors_points, _ = project_easy(world_coord_points, rvec, tvec, (res_w, res_h), USE_DISTORTION)
                image_coors_points = image_coors_points.reshape(-1, 2)  # cv2.projectPoints outputs (-1, 1, 2).
                #                                                         I don´t know why

                cv2.arrowedLine(reprojected_image, tuple(image_coors_points[0]), tuple(image_coors_points[1]), red, 5,
                                cv2.LINE_AA)
                cv2.arrowedLine(reprojected_image, tuple(image_coors_points[0]), tuple(image_coors_points[2]), green, 5,
                                cv2.LINE_AA)
                cv2.arrowedLine(reprojected_image, tuple(image_coors_points[0]), tuple(image_coors_points[3]), blue, 5,
                                cv2.LINE_AA)

                # axis description
                cv2.putText(reprojected_image, "X-Axis", (50, 50), font, 1, red, 2, cv2.LINE_AA)
                cv2.putText(reprojected_image, "Y-Axis", (50, 100), font, 1, green, 2, cv2.LINE_AA)
                cv2.putText(reprojected_image, "Z-Axis", (50, 150), font, 1, blue, 2, cv2.LINE_AA)

                cv2.imshow('reprojected_image', reprojected_image)

    cap.release()


def check_chessboard_layout():
    x_even = PATTERN_SIZE[0] % 2 == 0
    y_even = PATTERN_SIZE[1] % 2 == 0
    if x_even == y_even:
        raise Exception(
            'Chessboard has to have either an even number of rows and an odd number of columns or an odd number of '
            'rows and an even number of columns!'
            '\nThis is due to the issue with generating the object points in the correct orientation...')


if __name__ == '__main__':
    check_chessboard_layout()

    main()
