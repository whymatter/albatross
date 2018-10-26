import cv2
import numpy as np
from math import fabs
import time

THRESHOLD_AREA_RANGE_MIN = 1000
THRESHOLD_AREA_RANGE_MAX = 11000
THRESHOLD_DELTA_ANGLE = 20
THRESHOLD_MIN_RATIO = 0.65  # short-side / long-side
THRESHOLD_MAX_RATIO = 0.90  # short-side / long-side

SHOW_BOUNDING = True
SHOW_MINIMAL = False


def is_contour_cup_bounding(cnt, position, size):
    global contour_bounding_box
    x, y = position
    width, height = size

    if contour_bounding_box is not None:
        minX, minY = contour_bounding_box[0]
        maxX, maxY = contour_bounding_box[1]

        if not (minX <= x <= maxX and minY <= y <= maxY and maxX - minX > width and maxY - minY > height):
            return False

    print(width, height, cv2.contourArea(cnt))
    if THRESHOLD_AREA_RANGE_MIN <= cv2.contourArea(cnt) <= THRESHOLD_AREA_RANGE_MAX:
        # return True
        if THRESHOLD_MIN_RATIO <= width / height <= THRESHOLD_MAX_RATIO:
            return True
        else:
            return False
    else:
        return False


def is_contour_cup(cnt, rect):
    global contour_bounding_box
    x, y = rect[0]
    width, height = rect[1]
    angle = rect[2]

    if contour_bounding_box is not None:
        minX, minY = contour_bounding_box[0]
        maxX, maxY = contour_bounding_box[1]

        if not (minX <= x <= maxX and minY <= y <= maxY and maxX - minX > width and maxY - minY > height):
            return False

    print(width, height, angle, cv2.contourArea(cnt))
    if THRESHOLD_AREA_RANGE_MIN <= cv2.contourArea(cnt) <= THRESHOLD_AREA_RANGE_MAX:
        # return True
        if width < height:
            if fabs(angle) < THRESHOLD_DELTA_ANGLE:
                if THRESHOLD_MIN_RATIO <= width / height <= THRESHOLD_MAX_RATIO:
                    return True
                else:
                    return False
            else:
                return False
        else:
            if (90 - THRESHOLD_DELTA_ANGLE) < fabs(angle):
                if THRESHOLD_MIN_RATIO <= height / width <= THRESHOLD_MAX_RATIO:
                    return True
                else:
                    return False
            else:
                return False
    else:
        return False


start_point = None
contour_bounding_box = None


def frame_on_mouse(event, x, y, flags, param):
    global contour_bounding_box
    global start_point
    current_point = (x, y)
    if event == cv2.EVENT_LBUTTONDOWN:
        start_point = current_point
    elif event == cv2.EVENT_MOUSEMOVE and start_point is not None:
        contour_bounding_box = (start_point[:], current_point[:])
    elif event == cv2.EVENT_LBUTTONUP:
        start_point = None


def callback(value):
    pass


cv2.namedWindow('mask')
cv2.createTrackbar('L-H', 'mask', 110, 180, callback)
cv2.createTrackbar('L-S', 'mask', 94, 255, callback)
cv2.createTrackbar('L-V', 'mask', 48, 255, callback)
cv2.createTrackbar('H-H', 'mask', 127, 180, callback)
cv2.createTrackbar('H-S', 'mask', 228, 255, callback)
cv2.createTrackbar('H-V', 'mask', 129, 255, callback)

cv2.namedWindow('frame')
cv2.setMouseCallback('frame', frame_on_mouse)

cap = cv2.VideoCapture(0)
lastTime = time.clock()
fps_count_max = 10
fps_count = fps_count_max - 1
last_fps = 0
while True:
    # Take each frame
    _, frame = cap.read()
    # frame = cv2.imread('Unbenannt.png')
    # Convert BGR to HSV
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    # hsv = cv2.GaussianBlur(hsv, (5, 5), 0)
    hsv = cv2.medianBlur(hsv, 9)

    # define range of blue color in HSV
    lh = cv2.getTrackbarPos('L-H', 'mask')
    ls = cv2.getTrackbarPos('L-S', 'mask')
    lv = cv2.getTrackbarPos('L-V', 'mask')
    hh = cv2.getTrackbarPos('H-H', 'mask')
    hs = cv2.getTrackbarPos('H-S', 'mask')
    hv = cv2.getTrackbarPos('H-V', 'mask')

    lower_blue = np.array([lh, ls, lv])
    upper_blue = np.array([hh, hs, hv])
    # Threshold the HSV image to get only blue colors
    mask = cv2.inRange(hsv, lower_blue, upper_blue)
    # Bitwise-AND mask and original image
    res = cv2.bitwise_and(frame, frame, mask=mask)

    # fps
    fps_count = fps_count + 1
    if fps_count == fps_count_max:
        current_time = time.clock()
        last_fps = int(fps_count_max / (current_time - lastTime))
        lastTime = current_time
        fps_count = 0

    cv2.putText(frame, 'FPS: {}'.format(last_fps), (10, 50),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 255))

    im2, contours, hierarchy = cv2.findContours(mask, 1, 2)
    if len(contours) > 0:
        area = max([cv2.contourArea(cnt) for cnt in contours])
        # print(len(contours), area)
        for cnt in contours:
            x, y, w, h = cv2.boundingRect(cnt)
            if SHOW_BOUNDING and is_contour_cup_bounding(cnt, (x, y), (w, h)):
                cv2.rectangle(res, (x, y), (x + w, y + h), (255, 0, 0), 2)
                cv2.rectangle(frame, (x, y), (x + w, y + h), (255, 0, 0), 2)

            rect = cv2.minAreaRect(cnt)
            box = cv2.boxPoints(rect)
            if SHOW_MINIMAL and is_contour_cup(cnt, rect):
                box = np.intp(box)
                cv2.drawContours(res, [box], 0, (0, 0, 255), 2)
                cv2.drawContours(frame, [box], 0, (0, 0, 255), 2)

    if contour_bounding_box is not None:
        cv2.rectangle(frame, contour_bounding_box[0], contour_bounding_box[1], (0, 255, 0), 2)
    cv2.imshow('frame', frame)
    cv2.imshow('res', res)
    cv2.imshow('mask', mask)

    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
exit()
