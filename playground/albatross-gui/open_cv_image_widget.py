from PyQt5 import QtWidgets, QtCore, QtGui
import cv2


class OpenCVImageWidget(QtWidgets.QWidget):
    def __init__(self, parent=None):
        super(OpenCVImageWidget, self).__init__(parent)
        self.image = None

    def set_image(self, window_width, window_height, img):
        img_height, img_width, _ = img.shape
        scale_w = float(window_width) / float(img_width)
        scale_h = float(window_height) / float(img_height)
        scale = min([scale_w, scale_h])

        if scale == 0:
            scale = 1

        img = cv2.resize(img, None, fx=scale, fy=scale, interpolation=cv2.INTER_CUBIC)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        height, width, bpc = img.shape
        bytes_per_line = bpc * width

        self.image = QtGui.QImage(img.data, width, height, bytes_per_line, QtGui.QImage.Format_RGB888)
        self.setMinimumSize(self.image.size())
        self.update()

    def paintEvent(self, event):
        qp = QtGui.QPainter()
        qp.begin(self)
        if self.image:
            qp.drawImage(QtCore.QPoint(0, 0), self.image)
        qp.end()
