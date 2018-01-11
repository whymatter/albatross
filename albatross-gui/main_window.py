import sys

from PyQt5 import QtWidgets, QtCore, uic
from PyQt5.QtWidgets import QApplication

from multiprocessing import Queue

from car_state import CarState
from open_cv_image_widget import OpenCVImageWidget
from open_cv_capture_thread import OpenCVCaptureThread
# from pwm_adapter import initialize_pwm, change_duty_cycle, release_all
from pwm_network_adapter import initialize_pwm, change_duty_cycle, release_all

UI_FILES_FOLDER = './ui/'
MAIN_WINDOW_UI_FILE = 'main_window.ui'

STEERING_BCM_PIN = 13
SPEED_BCM_PIN = 12

SLIDER_MIN_VALUE = 0
SLIDER_MAX_VALUE = 100


class MainWindow(QtWidgets.QWidget):
    def __init__(self, parent=None):
        super(MainWindow, self).__init__(parent)

        self.car_state = None
        self.ui_elements = uic.loadUi(UI_FILES_FOLDER + MAIN_WINDOW_UI_FILE)

        self.ui_elements.btn_initialize.clicked.connect(self.__on_initialize_clicked)
        self.ui_elements.btn_reset.clicked.connect(self.__on_reset_clicked)

        self.ui_elements.btn_control_camera.clicked.connect(self.__on_control_camera_clicked)

        self.ui_elements.slider_steering.setRange(SLIDER_MIN_VALUE, SLIDER_MAX_VALUE)
        self.ui_elements.slider_steering.setValue(50)
        self.ui_elements.slider_speed.setRange(SLIDER_MIN_VALUE, SLIDER_MAX_VALUE)
        self.ui_elements.slider_speed.setValue(50)

        self.ui_elements.slider_steering.sliderMoved.connect(self.__on_steering_moved)
        self.ui_elements.slider_speed.sliderMoved.connect(self.__on_speed_moved)

        self.__initialize_camera()

        self.__disable_controls()

    def closeEvent(self, event):
        # does not get called!
        print("here")
        if self.capture_thread.is_alive():
            self.capture_thread.stop()
            self.capture_thread.join()

    def __initialize_camera(self):
        self.cam_state = "NI"
        self.queue = Queue()
        self.capture_thread = OpenCVCaptureThread(0, self.queue, 1920, 1080, 30)

        self.ui_elements.gv_camera_image = OpenCVImageWidget(self.ui_elements.gv_camera_image)

        self.timer = QtCore.QTimer(self)
        self.timer.timeout.connect(self.__update_camera_frame)
        self.timer.start(1)

    def __update_camera_frame(self):
        if not self.queue.empty():
            frame = self.queue.get()
            img = frame["img"]

            window_width = self.ui_elements.gv_camera_image.frameSize().width()
            window_height = self.ui_elements.gv_camera_image.frameSize().height()
            print(window_width, window_height)
            self.ui_elements.gv_camera_image.set_image(1000, 500, img)

    def __on_control_camera_clicked(self):
        if self.cam_state == "NI":
            self.capture_thread.start()
            self.cam_state = "R"
            self.ui_elements.btn_control_camera.setText("Running (Stop)")
        elif self.cam_state == "R":
            self.capture_thread.pause()
            self.cam_state = "P"
            self.ui_elements.btn_control_camera.setText("Paused (Resume)")
        elif self.cam_state == "P":
            self.capture_thread.resume()
            self.cam_state = "R"
            self.ui_elements.btn_control_camera.setText("Running (Stop)")

    def __display_car_state(self):
        if self.car_state is not None:
            lcd_text = repr(self.car_state.get_speed()) + " " + repr(self.car_state.get_steering())
            self.ui_elements.lcd_speed_n_steering.display(lcd_text)
        else:
            self.ui_elements.lcd_speed_n_steering.display("0.0 0.0")

    def __disable_controls(self):
        self.ui_elements.slider_steering.setEnabled(False)
        self.ui_elements.slider_speed.setEnabled(False)
        self.__display_car_state()

    def __enable_controls(self):
        self.ui_elements.slider_steering.setEnabled(True)
        self.ui_elements.slider_speed.setEnabled(True)
        self.__display_car_state()

    def __on_initialize_clicked(self):
        release_all()

        steering_index = initialize_pwm(STEERING_BCM_PIN)
        speed_index = initialize_pwm(SPEED_BCM_PIN)
        self.car_state = CarState(steering_index, speed_index)
        self.ui_elements.slider_steering.setValue(50)
        self.ui_elements.slider_speed.setValue(50)
        self.__enable_controls()
        self.__display_car_state()

    def __on_steering_moved(self, new_value):
        if self.car_state is not None:
            proportion = new_value / SLIDER_MAX_VALUE
            if change_duty_cycle(self.car_state.get_steering_index(), proportion):
                self.car_state.set_steering(proportion)
                self.__display_car_state()

    def __on_speed_moved(self, new_value):
        if self.car_state is not None:
            proportion = new_value / SLIDER_MAX_VALUE
            if change_duty_cycle(self.car_state.get_speed_index(), proportion):
                self.car_state.set_speed(proportion)
                self.__display_car_state()

    def __on_reset_clicked(self):
        if self.car_state is not None:
            release_all()
            self.car_state = None
            self.__disable_controls()


if __name__ == "__main__":
    app = QApplication(sys.argv)
    main_window = MainWindow()
    main_window.ui_elements.show()
    sys.exit(app.exec_())
