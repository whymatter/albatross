import numpy as np
import cv2
import math
import matplotlib.pyplot as plt


def rotation_matrix(axis, theta):
    """
    Return the rotation matrix associated with counterclockwise rotation about
    the given axis by theta radians.
    """
    axis = np.asarray(axis)
    axis = axis / math.sqrt(np.dot(axis, axis))
    a = math.cos(theta / 2.0)
    b, c, d = -axis * math.sin(theta / 2.0)
    aa, bb, cc, dd = a * a, b * b, c * c, d * d
    bc, ad, ac, ab, bd, cd = b * c, a * d, a * c, a * b, b * d, c * d
    return np.array([[aa + bb - cc - dd, 2 * (bc + ad), 2 * (bd - ac)],
                     [2 * (bc - ad), aa + cc - bb - dd, 2 * (cd + ab)],
                     [2 * (bd + ac), 2 * (cd - ab), aa + dd - bb - cc]])


last_position = None
points = [[], []]
plt.ion()


def transform_to_world(event, x, y, flags, param):
    global last_position
    global points
    global mtx
    world = get_world_coordinates(
        np.array([x, y]),
        mtx,
        np.array([0, 240, 0]),
        rotation_matrix([1, 0, 0], 15 * math.pi / 180),
        0)

    current_position = world
    if event == cv2.EVENT_LBUTTONDOWN:
        print([x, y], world)
        last_position = current_position
    elif event == cv2.EVENT_LBUTTONUP and last_position is not None:
        delta = last_position - current_position
        # print(np.linalg.norm(delta))
        points[0].append(current_position[0])
        points[1].append(current_position[2])
        plt.scatter(points[0], points[1])

    # print(world)


def get_world_coordinates(pixel_coords, camera_matrix, camera_translation, camera_rotation, y=0):
    ret, inv_camera_rotation = cv2.invert(camera_rotation)
    if not ret:
        return

    c = camera_matrix[:-1, 2]
    f = camera_matrix.reshape(9)[:-3:4]

    # print('c', c)
    # print('f', f)

    camera_point = np.append(((pixel_coords - c) / f), 1)
    # print('camera_point', camera_point)
    camera_point_rotated = np.dot(inv_camera_rotation, camera_point)
    # print('camera_point_rotated', camera_point_rotated)

    translation_rotated = np.dot(inv_camera_rotation, camera_translation)

    z = (y + translation_rotated[1]) / camera_point_rotated[1]
    return z * camera_point_rotated - translation_rotated


mtx = np.array([
    [1800.000846388783, 0, 960],
    [0, 1800.000846388783, 540],
    [0, 0, 1]
])
dist = np.array([[0.1045554918462832, -0.1699402592719769, 0, 0, -0.1637257699614786]])

fakex = 146
fakey = 692
transform_to_world(cv2.EVENT_LBUTTONDOWN, fakex, fakey, None, None)
transform_to_world(cv2.EVENT_LBUTTONUP, fakex, fakey, None, None)

fakex = 550
fakey = 370
transform_to_world(cv2.EVENT_LBUTTONDOWN, fakex, fakey, None, None)
transform_to_world(cv2.EVENT_LBUTTONUP, fakex, fakey, None, None)

mapx, mapy = None, None
roi = None

cap = cv2.VideoCapture(0)
cap.set(3,1920)
cap.set(4,1080)

cv2.namedWindow('img')
cv2.setMouseCallback('img', transform_to_world)
while True:
    ret, img = cap.read()
    if not ret:
        print('error reading frame from web cam')
        continue

    # init remap
    if mapx is None:
        h, w = img.shape[:2]
        newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))
        mapx, mapy = cv2.initUndistortRectifyMap(mtx, dist, None, newcameramtx, (w, h), 5)

    # remap
    # img = cv2.remap(img, mapx, mapy, cv2.INTER_LINEAR)
    # x, y, w, h = roi
    # img = img[y:y + h, x:x + w]
    cv2.imshow('img', img)

    # handle keypress
    key_code = cv2.waitKey(1) & 0xFF
    if key_code == ord('q'):
        cv2.destroyAllWindows()
        break

cv2.destroyAllWindows()
exit()
