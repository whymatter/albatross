import sys

import cv2
import numpy as np

from PyQt5 import QtCore
from PyQt5 import QtWidgets
from PyQt5 import QtGui
from PyQt5.QtGui import QImage


class VideoCapture(QtCore.QObject):
    image_data = QtCore.pyqtSignal(np.ndarray)

    def __init__(self, camera_port=0, parent=None):
        super().__init__(parent)
        self.camera = cv2.VideoCapture(camera_port)
        self.timer = QtCore.QBasicTimer()

    def start_recording(self):
        self.timer.start(0, self)

    def timerEvent(self, event):
        # I guess this is to make sure timerEvent is not called by any other time
        if event.timerId() != self.timer.timerId():
            return

        read, data = self.camera.read()
        if read:
            self.image_data.emit(data)


class VideoWidget(QtWidgets.QWidget):
    def __init__(self, parent=None):
        super().__init__(parent)
        self.image = QtGui.QImage()

    def image_data_slot(self, image_data):
        self.image = self.get_qimage(image_data)
        if self.image.size() != self.size():
            self.setFixedSize(self.image.size())

        self.update()

    @staticmethod
    def get_qimage(image: np.ndarray):
        height, width = image.shape[:2]
        colors = 1
        if len(image.shape) == 3:
            colors = image.shape[2]

        bytes_per_line = colors * width  # hope this correct

        # might be a bit hacky but I hope it works
        image_format = QImage.Format_RGB888 if colors == 3 else QImage.Format_Grayscale8

        image = QImage(image.data,
                       width,
                       height,
                       bytes_per_line,
                       image_format)

        # open cv uses BGR format so we swap RGB to BGR...
        if colors == 3:
            image = image.rgbSwapped()

        return image

    def paintEvent(self, event):
        painter = QtGui.QPainter(self)
        painter.drawImage(0, 0, self.image)
        self.image = QtGui.QImage()


class MainWidget(QtWidgets.QWidget):
    hsv_full_image = QtCore.pyqtSignal(np.ndarray)
    hsv_mask_image = QtCore.pyqtSignal(np.ndarray)
    hsv_masked_image = QtCore.pyqtSignal(np.ndarray)

    def __init__(self, parent=None):
        super().__init__(parent)
        self.record_video = VideoCapture()

        # hsv slider
        hsv = self.__init_hsv()

        layout = QtWidgets.QVBoxLayout()
        layout.addWidget(hsv)

        self.setLayout(layout)
        self.record_video.start_recording()

    def __init_hsv(self):
        self.s_hsv_h_min = self.create_slider(0, 180)
        self.s_hsv_h_max = self.create_slider(0, 180)
        self.s_hsv_s_min = self.create_slider(0, 255)
        self.s_hsv_s_max = self.create_slider(0, 255)
        self.s_hsv_v_min = self.create_slider(0, 255)
        self.s_hsv_v_max = self.create_slider(0, 255)
        self.v_hsv_full = VideoWidget()
        self.v_hsv_mask = VideoWidget()
        self.v_hsv_masked = VideoWidget()
        hsv_control = self.create_slider_widget(
            self.s_hsv_h_min,
            self.s_hsv_h_max,
            self.s_hsv_s_min,
            self.s_hsv_s_max,
            self.s_hsv_v_min,
            self.s_hsv_v_max
        )
        hsv_layout = QtWidgets.QHBoxLayout()
        hsv_layout.addWidget(hsv_control)
        hsv_layout.addWidget(self.v_hsv_full)
        hsv_layout.addWidget(self.v_hsv_mask)
        hsv_layout.addWidget(self.v_hsv_masked)
        hsv = QtWidgets.QWidget()
        hsv.setLayout(hsv_layout)
        self.record_video.image_data.connect(self.hsv_conversion)
        self.hsv_full_image.connect(self.v_hsv_full.image_data_slot)
        self.hsv_mask_image.connect(self.v_hsv_mask.image_data_slot)
        self.hsv_masked_image.connect(self.v_hsv_masked.image_data_slot)

        return hsv

    def hsv_conversion(self, image_data: np.ndarray):
        self.hsv_full_image.emit(image_data)

        blured = cv2.GaussianBlur(image_data, (5, 5), 0)

        hsv = cv2.cvtColor(blured, cv2.COLOR_BGR2HSV)
        lower = np.array([self.s_hsv_h_min.value(), self.s_hsv_s_min.value(), self.s_hsv_v_min.value()])
        upper = np.array([self.s_hsv_h_max.value(), self.s_hsv_s_max.value(), self.s_hsv_v_max.value()])
        mask = cv2.inRange(hsv, lower, upper)

        # rects = cv2.cvtColor(image_data, cv2.COLOR_BGR2GRAY)
        self.hsv_mask_image.emit(mask)
        copy = image_data[:, :, :]
        mask = cv2.bitwise_not(mask)
        im2, contours, hierarchy = cv2.findContours(mask, 1, 2)
        for cnt in contours:
            rect = cv2.minAreaRect(cnt)
            box = cv2.boxPoints(rect)
            box = np.intp(box)
            cv2.drawContours(copy, [box], 0, (0, 0, 255), 2)

        masked = cv2.bitwise_and(copy, copy, mask=mask)
        self.hsv_masked_image.emit(masked)

    @staticmethod
    def create_slider_widget(*args):
        widget = QtWidgets.QWidget()
        layout = QtWidgets.QVBoxLayout()
        widget.setLayout(layout)
        for slider in args:
            layout.addWidget(slider)
        widget.setFixedWidth(200)
        return widget

    @staticmethod
    def create_slider(_min, _max):
        slider = QtWidgets.QSlider(QtCore.Qt.Horizontal)
        slider.setRange(_min, _max)
        return slider


def main():
    app = QtWidgets.QApplication(sys.argv)

    main_window = QtWidgets.QMainWindow()
    main_widget = MainWidget()
    main_window.setCentralWidget(main_widget)
    main_window.show()
    sys.exit(app.exec_())


if __name__ == '__main__':
    main()
