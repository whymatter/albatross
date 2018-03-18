import numpy as np
import cv2
import datetime
import os

SQUARE_SIZE = 24
NOW = str(datetime.datetime.now())[:-7].replace(' ', '-').replace(':', '-')

# termination criteria
criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 30, 0.001)

# prepare object points, like (0,0,0), (1,0,0), (2,0,0) ....,(6,5,0)
object_point = np.zeros((7 * 7, 3), np.float32)
object_point[:, :2] = np.mgrid[0:7, 0:7].T.reshape(-1, 2) * SQUARE_SIZE

# Arrays to store object points and image points from all the images.
object_points = []  # 3d point in real world space
img_points = []  # 2d points in image plane.

cap = cv2.VideoCapture(0)

NOW = '2018-01-28-20-36-49'
os.makedirs('./' + NOW + '/', exist_ok=True)
i = 0
files = list([f for f in os.listdir('./' + NOW)])
for f in files:
    img = cv2.imread('./{}/'.format(NOW) + f)

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Find the chess board corners
    print('find chessboard')
    ret, corners = cv2.findChessboardCorners(gray, (7, 7), None)
    print('chessboard found: ', ret)

    # If found, add object points, image points (after refining them)
    if ret:
        object_points.append(object_point)

        cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
        img_points.append(corners)

        # Draw and display the corners
        # cv2.drawChessboardCorners(img, (7, 7), corners, ret)
        # cv2.imshow('img', img)

while False:
    ret, img = cap.read()
    if not ret:
        print('error reading frame from web cam')
        continue

    cv2.imshow('img', img)

    # handle keypress
    key_code = cv2.waitKey(1) & 0xFF
    if key_code == ord(' '):
        pass
    elif key_code == ord('c'):
        break
    else:
        continue

    gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

    # Find the chess board corners
    print('find chessboard')
    ret, corners = cv2.findChessboardCorners(gray, (7, 7), None)
    print('chessboard found: ', ret)

    # If found, add object points, image points (after refining them)
    if ret:
        object_points.append(object_point)

        cv2.cornerSubPix(gray, corners, (11, 11), (-1, -1), criteria)
        img_points.append(corners)

        # save image
        cv2.imwrite('./{}/{}.png'.format(NOW, i), img)

        # Draw and display the corners
        cv2.drawChessboardCorners(img, (7, 7), corners, ret)
        cv2.imshow('img', img)
        i += 1
        print('successful images: ', i)

ret, mtx, dist, rvecs, tvecs = cv2.calibrateCamera(object_points, img_points, gray.shape[::-1], None, None)
print('ret: ', ret)

# while True:
#     ret, img = cap.read()
#     if not ret:
#         print('error reading frame from web cam')
#         continue
#
#     h, w = img.shape[:2]
#     newcameramtx, roi = cv2.getOptimalNewCameraMatrix(mtx, dist, (w, h), 1, (w, h))
#     dst = cv2.undistort(img, mtx, dist, None, newcameramtx)
#     x, y, w, h = roi
#     dst = dst[y:y + h, x:x + w]
#     cv2.imshow('img', dst)
#
#     if cv2.waitKey(1) & 0xFF == ord('w'):
#         break

# calculate error
mean_error = 0
for i in range(len(object_points)):
    imgpoints2, _ = cv2.projectPoints(object_points[i], rvecs[i], tvecs[i], mtx, dist)
    error = cv2.norm(img_points[i], imgpoints2, cv2.NORM_L2) / len(imgpoints2)
    mean_error += error
print("total error: ", mean_error / len(object_points))

# persist
file = open('./{}/parameters.txt'.format(NOW), 'w+')
np.set_printoptions(threshold=800 * 10)
file.write(repr({
    'mtx': np.array2string(mtx),
    'dist': np.array2string(dist),
    # 'rvecs': np.array2string(np.array(rvecs)),
    # 'tvecs': np.array2string(np.array(tvecs))
}).replace('\\n', '\n'))
file.close()

cv2.destroyAllWindows()
