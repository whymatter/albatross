import sys

from PyQt5 import QtWidgets, uic
from PyQt5.QtWidgets import QApplication

from car_state import CarState
from pwm_adapter import initialize_pwm, change_duty_cycle, release_all

UI_FILES_FOLDER = './ui/'
MAIN_WINDOW_UI_FILE = 'main_window.ui'

STEERING_BCM_PIN = 13
SPEED_BCM_PIN = 12

SLIDER_MIN_VALUE = 0
SLIDER_MAX_VALUE = 100


class MainWindow(QtWidgets.QWidget):
    def __init__(self):
        QtWidgets.QWidget.__init__(self)

        self.car_state = None
        self.ui_elements = uic.loadUi(UI_FILES_FOLDER + MAIN_WINDOW_UI_FILE)

        self.ui_elements.btn_initialize.clicked.connect(self.__on_initialize_clicked)
        self.ui_elements.btn_reset.clicked.connect(self.__on_reset_clicked)

        self.ui_elements.slider_steering.setRange(SLIDER_MIN_VALUE, SLIDER_MAX_VALUE)
        self.ui_elements.slider_steering.setValue(50)
        self.ui_elements.slider_speed.setRange(SLIDER_MIN_VALUE, SLIDER_MAX_VALUE)
        self.ui_elements.slider_speed.setValue(50)

        self.ui_elements.slider_steering.sliderMoved.connect(self.__on_steering_moved)
        self.ui_elements.slider_speed.sliderMoved.connect(self.__on_speed_moved)

        self.__disable_controls()

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
