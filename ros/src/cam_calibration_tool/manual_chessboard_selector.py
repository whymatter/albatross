import numpy as np
import cv2


class ManualChessboardSelector:
    def __init__(self, resolution):
        self.mouse_x = 0
        self.mouse_y = 0

        self.zoomFactor = 1
        self.lastZoomFactor = 1
        self.zoom_x = 0
        self.zoom_y = 0
        self.real_zoom_x = 0
        self.real_zoom_y = 0

        self.click_x = 0
        self.click_y = 0
        self.click = False

        self.last_min_x = 0
        self.last_min_y = 0

        self.resolution = resolution

        cv2.namedWindow('magnifier')
        cv2.setMouseCallback('magnifier', self.cam_image_callback)

    def cam_image_callback(self, event, x, y, flags, param):
        if event == cv2.EVENT_MOUSEHWHEEL:
            # if scrolled
            self.zoom_x, self.zoom_y = self.mouse_x, self.mouse_y
            if flags == 65568:
                self.zoomFactor = min(self.zoomFactor + 0.01, 1)
            else:
                self.zoomFactor = max(self.zoomFactor - 0.01, 0.01)
        elif event == cv2.EVENT_LBUTTONDOWN:
            # if clicked
            self.click_x, self.click_y, self.click = self.mouse_x, self.mouse_y, True
        else:
            # if mouse moved
            self.mouse_x, self.mouse_y = x, y

    @staticmethod
    def calc_window(m, s, z, minp):
        ws = s * z

        min_ = m - ws * minp
        min_c = max(min_, 0)

        max_ = m + ws * (1 - minp)
        max_c = min(max_, s)

        omin = min_c - min_
        omax = max_ - max_c

        if omin != 0.0 and omax != 0.0:
            print('error: overflowing in both directions %d %d' % (omin, omax))
            return 0, s

        return int(min_c - omax), int(max_c + omin)

    def zooming(self, current_image, corners):
        if self.zoomFactor != self.lastZoomFactor:
            self.real_zoom_x = self.last_min_x + self.zoom_x * self.lastZoomFactor
            self.real_zoom_y = self.last_min_y + self.zoom_y * self.lastZoomFactor

        if self.click:
            self.click = False
            self.click_x = self.last_min_x + self.click_x * self.lastZoomFactor
            self.click_y = self.last_min_y + self.click_y * self.lastZoomFactor

            if corners is None:
                corners = np.array([[self.click_x, self.click_y]])
            else:
                corners = np.append(corners, [[self.click_x, self.click_y]], axis=0)

        min_x, max_x = ManualChessboardSelector.calc_window(self.real_zoom_x, self.resolution[0], self.zoomFactor,
                                                            (self.real_zoom_x - self.last_min_x) / (
                                                                    self.resolution[0] * self.lastZoomFactor))
        min_y, max_y = ManualChessboardSelector.calc_window(self.real_zoom_y, self.resolution[1], self.zoomFactor,
                                                            (self.real_zoom_y - self.last_min_y) / (
                                                                    self.resolution[1] * self.lastZoomFactor))

        self.lastZoomFactor, self.last_min_x, self.last_min_y = self.zoomFactor, min_x, min_y

        to_magnify = current_image.copy()

        if corners is not None:
            for corner in corners:
                cv2.circle(to_magnify, tuple(corner.astype(np.int32)), 4, (0, 0, 255))

        to_magnify = to_magnify[min_y:max_y, min_x:max_x, :]
        to_magnify = cv2.resize(to_magnify, (self.resolution[0], self.resolution[1]))
        cv2.circle(to_magnify, (self.mouse_x, self.mouse_y), 10, (255, 0, 0))

        cv2.imshow('magnifier', to_magnify)

        return corners
