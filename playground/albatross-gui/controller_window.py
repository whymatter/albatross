from PyQt5 import QtWidgets
from PyQt5.QtCore import QPoint, QTimer, pyqtSignal
from PyQt5.QtGui import QPainter, QColor
from PyQt5.QtWidgets import QApplication

import functools

from math import fabs, log, exp, copysign

CONTROLLER_WIDTH = 300
MOUSE_RECT_FACTOR = 1 / 20
HISTORY_LENGTH = 10


def get_mouse_rect(window_width, window_height):
    return window_width * MOUSE_RECT_FACTOR, window_height * MOUSE_RECT_FACTOR


def get_controller_window_padding(mouse_rect):
    return mouse_rect[0] / 2, mouse_rect[1] / 2


def get_controller_rect(window_width, window_height, controller_window_padding):
    return window_width - controller_window_padding[0] * 2, window_height - controller_window_padding[1] * 2


class DrawCircles(QtWidgets.QWidget):
    controller_moved = pyqtSignal(float, float)

    def __init__(self, parent=None):
        QtWidgets.QWidget.__init__(self, parent)
        self.setGeometry(800, 400, CONTROLLER_WIDTH, CONTROLLER_WIDTH)
        self.setWindowTitle("Controller")
        self.mouse_position_history = []
        self.mouse_position = None
        self.mouse_position_eased = None
        self.controller_percentage = None

        self.pressed = False

        self.timer = QTimer()
        self.timer.setInterval(1)
        self.timer.start()
        self.timer.timeout.connect(self.timeout)

    def timeout(self):
        if not self.pressed:
            return
        position = self.mapFromGlobal(self.cursor().pos())
        self.mouse_position = position
        self.push_mouse_position(self.mouse_position)
        self.refresh_mouse_position_eased()
        self.refresh_controller_percentage()
        self.repaint()

    def mousePressEvent(self, q_mouse_event):
        self.pressed = True

    def mouseMoveEvent(self, q_mouse_event):
        pass

    def mouseReleaseEvent(self, q_mouse_event):
        self.mouse_position_history = [QPoint(self.width() // 2, self.height() // 2)]
        self.refresh_mouse_position_eased()
        self.refresh_controller_percentage()
        self.repaint()
        self.pressed = False

    def push_mouse_position(self, mouse_position):
        if len(self.mouse_position_history) == HISTORY_LENGTH:
            self.mouse_position_history[:] = self.mouse_position_history[1:] + [mouse_position]
        else:
            self.mouse_position_history.append(mouse_position)

    def refresh_mouse_position_eased(self):
        # smoothing
        history_length = len(self.mouse_position_history)
        weights_sum = history_length * (history_length + 1) * 0.5
        positions_weighted = [(pos.x() * (i + 1) / weights_sum, pos.y() * (i + 1) / weights_sum) for i, pos in
                              enumerate(self.mouse_position_history)]
        mouse_position_smoothed = functools.reduce(lambda x, y: (x[0] + y[0], x[1] + y[1]), positions_weighted)

        # spring
        center_x, center_y = self.width() / 2, self.height() / 2
        delta_x, delta_y = mouse_position_smoothed[0] - center_x, mouse_position_smoothed[1] - center_y
        delta_x_abs, delta_y_abs = fabs(delta_x), fabs(delta_y)

        if delta_x_abs < 6.68:
            damping_x = exp(0.2 * delta_x_abs) - 1
        else:
            if delta_x_abs == 7:
                damping_x = 3.050
            else:
                damping_x = 1.5 * (delta_x_abs - 7) / log(delta_x_abs - 6) + 1.55

        if delta_y_abs < 6.68:
            damping_y = exp(0.2 * delta_y_abs) - 1
        else:
            if delta_y_abs == 7:
                damping_y = 3.050
            else:
                damping_y = 1.5 * (delta_y_abs - 7) / log(delta_y_abs - 6) + 1.55

        self.mouse_position_eased = QPoint(int(center_x + copysign(damping_x, delta_x)),
                                           int(center_y + copysign(damping_y, delta_y)))

    def refresh_controller_percentage(self):
        mouse_position_center_relative = self.mouse_position_eased.x() - self.width() / 2, \
                                         self.mouse_position_eased.y() - self.height() / 2
        controller_rect = get_controller_rect(self.width(), self.height(),
                                              get_controller_window_padding(
                                                  get_mouse_rect(self.width(), self.height())))
        self.controller_percentage = mouse_position_center_relative[0] / (controller_rect[0] / 2), \
                                     -mouse_position_center_relative[1] / (controller_rect[1] / 2)
        self.controller_moved.emit(self.controller_percentage[0], self.controller_percentage[1])

    def paintEvent(self, event):
        paint = QPainter()
        paint.begin(self)
        paint.setPen(QColor.fromRgb(0, 0, 0, 0))
        paint.setRenderHint(QPainter.Antialiasing)

        window_width = event.rect().width()
        window_height = event.rect().height()

        mouse_rect = get_mouse_rect(window_width, window_height)
        controller_window_padding = get_controller_window_padding(mouse_rect)
        controller_rect = get_controller_rect(window_width, window_height, controller_window_padding)

        # window background
        paint.setBrush(QColor.fromRgb(0, 150, 255))
        paint.drawRect(0, 0, window_width, window_height)

        # controller rect
        paint.setBrush(QColor.fromRgb(0, 200, 255))
        paint.drawRect(controller_window_padding[0], controller_window_padding[1], controller_rect[0],
                       controller_rect[1])

        # mouse rect
        if self.mouse_position_eased is not None:
            paint.setBrush(QColor.fromRgb(0, 0, 255))
            mouse_rect_x = self.mouse_position_eased.x() - mouse_rect[0] / 2
            mouse_rect_y = self.mouse_position_eased.y() - mouse_rect[1] / 2

            # clip mouse_rect into controller rect
            if mouse_rect_x < controller_window_padding[0]:
                mouse_rect_x = controller_window_padding[0]

            if mouse_rect_y < controller_window_padding[1]:
                mouse_rect_y = controller_window_padding[1]

            if mouse_rect_x > window_width - controller_window_padding[0] - mouse_rect[0]:
                mouse_rect_x = window_width - controller_window_padding[0] - mouse_rect[0]

            if mouse_rect_y > window_height - controller_window_padding[1] - mouse_rect[1]:
                mouse_rect_y = window_height - controller_window_padding[1] - mouse_rect[1]

            paint.drawRect(mouse_rect_x, mouse_rect_y,
                           mouse_rect[0], mouse_rect[1])

            paint.setPen(QColor.fromRgb(255, 255, 255))
            paint.drawText(mouse_rect_x, mouse_rect_y - 20, 200, 20, 0,
                           repr(int(self.controller_percentage[0] * 100)) + "% " + repr(
                               int(self.controller_percentage[1] * 100)) + "%")
            paint.setPen(QColor.fromRgb(0, 0, 0, 0))

        # center lines
        paint.setPen(QColor.fromRgb(0, 0, 0))
        paint.drawLine(window_width / 2, controller_window_padding[1], window_width / 2,
                       window_height - controller_window_padding[1])
        paint.drawLine(controller_window_padding[0], window_height / 2, window_width - controller_window_padding[0],
                       window_height / 2)
        paint.setPen(QColor.fromRgb(0, 0, 0, 0))

        # end
        paint.end()


if __name__ == "__main__":
    app = QApplication([])
    circles = DrawCircles()
    circles.show()
    app.exec_()
