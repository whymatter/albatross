//
// Created by whymatter on 15.09.18.
//

#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;

int main(int argc, char **argv) {
    VideoCapture cap(0); // open the default camera
    if (!cap.isOpened())  // check if we succeeded
        return -1;

    cap.set(CV_CAP_PROP_FRAME_WIDTH, 1920);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 1080);

    Mat edges;
    namedWindow("preview", 1);
    bool loop = true;
    int img_nbr = 0;
    while (loop) {
        Mat frame;
        cap >> frame; // get a new frame from camera
        imshow("preview", frame);

        std::stringstream ss;
        switch (waitKey(10)) {
            case 32:
                ss << "/home/whymatter/Pictures/6/" << img_nbr++ << ".png";
                std::cout << ss.str().c_str() << std::endl;
                imwrite(ss.str().c_str(), frame);
                break;
            case -1:
                break;
            default:
                loop = false;
                break;
        }
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}