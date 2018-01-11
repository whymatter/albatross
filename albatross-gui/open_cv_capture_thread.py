import cv2
from threading import Thread, Lock, Condition


class OpenCVCaptureThread(Thread):
    def __init__(self, cam, queue, width, height, fps):
        Thread.__init__(self)
        # flag to pause thread
        self.running = True
        self.paused = False
        self.pause_cond = Condition(Lock())

        self.queue = queue

        self.capture = cv2.VideoCapture(cam)
        self.capture.set(cv2.CAP_PROP_FRAME_WIDTH, width)
        self.capture.set(cv2.CAP_PROP_FRAME_HEIGHT, height)
        self.capture.set(cv2.CAP_PROP_FPS, fps)

    def run(self):
        while self.running:
            with self.pause_cond:
                while self.paused:
                    self.pause_cond.wait()
                # thread should do the thing if
                # not paused
                self.push_frame()

    def stop(self):
        if self.paused:
            self.resume()
        self.running = False

    def pause(self):
        self.paused = True
        # If in sleep, we acquire immediately, otherwise we wait for thread
        # to release condition. In race, worker will still see self.paused
        # and begin waiting until it's set back to False
        self.pause_cond.acquire()

    def resume(self):
        self.paused = False
        # Notify so thread will wake after lock released
        self.pause_cond.notify()
        # Now release the lock
        self.pause_cond.release()

    def push_frame(self):
        self.capture.grab()
        _, img = self.capture.retrieve(0)
        frame = {
            "img": img
        }

        if self.queue.qsize() < 10:
            self.queue.put(frame)
        else:
            print("queue overloaded " + repr(self.queue.qsize()))
