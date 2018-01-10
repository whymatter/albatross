__PWM_BASE_WIDTH = 20.0  # ms

__PWM_MIN_WIDTH = 1.0  # ms
__PWM_CENTER_WIDTH = 1.5  # ms
__PWM_MAX_WIDTH = 2.0  # ms


def __ms_to_duty_cycle(ms):
    return ms / __PWM_BASE_WIDTH


__PWM_MIN_DC = __ms_to_duty_cycle(__PWM_MIN_WIDTH)
__PWM_CENTER_DC = __ms_to_duty_cycle(__PWM_CENTER_WIDTH)
__PWM_MAX_DC = __ms_to_duty_cycle(__PWM_MAX_WIDTH)

__PWM_STORE = []


def __ms_to_freq(ms):
    return 1 / (ms * 1000.0)


def initialize_pwm(bcm_pin_number):
    base_frequency = __ms_to_freq(__PWM_BASE_WIDTH)

    print("initialize pwm for bcm-pin " + repr(bcm_pin_number))
    print("using base width of " + repr(__PWM_BASE_WIDTH) + "ms")
    print(" => " + repr(base_frequency) + "hz")
    print("using center width of " + repr(__PWM_CENTER_WIDTH) + "ms")
    print(" => " + repr(__PWM_CENTER_DC) + "%")

    GPIO.setupmode(GPIO.BCM)
    GPIO.setup(bcm_pin_number, GPIO.OUT)
    pwm = GPIO.PWM(bcm_pin_number, base_frequency)
    pwm.start(__PWM_CENTER_DC)
    __PWM_STORE.append(pwm)
    return len(__PWM_STORE) - 1


def change_duty_cycle(pwm_index, proportion):
    if proportion < 0 or proportion > 1:
        print("invalid proportion " + repr(proportion) + "%")
        return False

    ms = __PWM_MIN_WIDTH + (__PWM_MAX_WIDTH - __PWM_MIN_WIDTH) * proportion
    new_duty_cycle = __ms_to_duty_cycle(ms)

    print("changing duty cycle to " + repr(ms) + "ms")
    print(" => " + repr(new_duty_cycle) + "%")

    pwm = __PWM_STORE[pwm_index]
    pwm.ChangeDutyCycle(new_duty_cycle)
    return True


def release_all():
    for pwm in __PWM_STORE:
        pwm.stop()
    __PWM_STORE.clear()
