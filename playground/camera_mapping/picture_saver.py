import numpy as np
import cv2
import datetime
import os

SQUARE_SIZE = 24
NOW = str(datetime.datetime.now())[:-7].replace(' ', '-').replace(':', '-')

cap = cv2.VideoCapture(1)

cap.set(3,1920)
cap.set(4,1080)

os.makedirs('./' + NOW)
i = 0
while True:
    ret, img = cap.read()
    cv2.imshow('img', img)

    key_code = cv2.waitKey(1) & 0xFF
    if key_code == ord(' '):
        gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

        # Find the chess board corners
        print('find chessboard')
        ret, corners = cv2.findChessboardCorners(gray, (7, 7), None)
        print('chessboard found: ', ret)

        # If found, add object points, image points (after refining them)
        if ret:
            print('successful: ', i)
            i = i + 1
            cv2.imwrite('./{0}/img-{1}.png'.format(NOW, i), img)
    elif key_code == ord('q'):
        break

cv2.destroyAllWindows()