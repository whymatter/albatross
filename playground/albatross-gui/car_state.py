class CarState:
    def __init__(self, steering_index, speed_index):
        self.__speed = 0.5
        self.__steering = 0.5

        self.__steering_index = steering_index
        self.__speed_index = speed_index

    def set_speed(self, new_speed):
        self.__speed = new_speed

    def get_speed(self):
        return self.__speed

    def set_steering(self, new_steering):
        self.__steering = new_steering

    def get_steering(self):
        return self.__steering

    def get_steering_index(self):
        return self.__steering_index

    def get_speed_index(self):
        return self.__speed_index
