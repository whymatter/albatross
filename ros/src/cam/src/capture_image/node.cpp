//
// Created by whymatter on 15.09.18.
//

#include "opencv2/opencv.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

using namespace cv;

int main(int argc, char **argv) {
    int opt_w = 640;
    int opt_h = 480;
    int opt_z = 100;
    int opt_a = 0;
    int opt_f = 0;
    char *opt_d;
    char c;

    while ((c = getopt(argc, argv, "w:h:z:af:d:")) != -1) {
        switch (c) {
            case 'w':
                opt_w = atoi(optarg);
                break;
            case 'h':
                opt_h = atoi(optarg);
                break;
            case 'z':
                opt_z = atoi(optarg);
                break;
            case 'a':
                opt_a = 1;
                break;
            case 'f':
                opt_f = atoi(optarg);
                break;
            case 'd':
                opt_d = optarg;
                break;
            case '?':
                if (optopt == 'w' || optopt == 'h' || optopt == 'z' || optopt == 'f' || optopt == 'd')
                    fprintf(stderr, "Options -%c require arguments.\n", optopt);
                else if (isprint(optopt))
                    fprintf(stderr, "Unknown option `-%c'.\n", optopt);
                else
                    fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
                return 1;
            default:
                abort();
        }
    }

    VideoCapture cap(0); // open the default camera
    if (!cap.isOpened())  // check if we succeeded
        return -1;

    cap.set(CV_CAP_PROP_FRAME_WIDTH, opt_w);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, opt_h);
//    cap.set(CV_CAP_PROP_ZOOM, opt_z); Not Working
//    cap.set(CV_CAP_PROP_AUTOFOCUS, opt_a); Not Working
//    cap.set(CV_CAP_PROP_FOCUS, opt_f); Not working

    std::ostringstream stringStream;
    stringStream << "v4l2-ctl -c focus_auto=" << opt_a;
    system(stringStream.str().c_str());

    if (opt_f >= 0 && opt_f <= 250) {
        std::ostringstream stringStream;
        stringStream << "v4l2-ctl -c focus_absolute=" << opt_f;
        system(stringStream.str().c_str());
    }

    if (opt_z >= 100 && opt_z <= 500) {
        std::ostringstream stringStream;
        stringStream << "v4l2-ctl -c zoom_absolute=" << opt_z;
        system(stringStream.str().c_str());
    }

    mkdir(opt_d, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

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
                ss << "/" << opt_d << "/" << img_nbr++ << ".png";
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