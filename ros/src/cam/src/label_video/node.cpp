//
// Created by whymatter on 15.09.18.
//

#include "opencv2/opencv.hpp"
#include <iostream>
#include <sys/stat.h>

using namespace cv;

#define VideoFile "/home/whymatter/Videos/video.mp4"
#define OutputFolder "/home/whymatter/Pictures/7"

#define Q_KEY 1048689
#define SPACE_KEY 1048608
#define ARROW_LEFT_KEY 1113937
#define ARROW_RIGHT_KEY 1113939
#define S_KEY 1048691

#define LABEL_IMG_HEIGHT 360

int main(int argc, char **argv) {

    const int dir_err = mkdir(OutputFolder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    if (-1 == dir_err)
    {
        std::cout << "error creating directory" << std::endl;
        return 0;
    }


    VideoCapture cap(VideoFile);
    if (!cap.isOpened()) {
        std::cout << "cant open video file" << std::endl;
        return -1;
    }

    int label_img_height = LABEL_IMG_HEIGHT;
    int label_img_width =
            ((int) cap.get(CAP_PROP_FRAME_WIDTH)) * label_img_height / ((int) cap.get(CAP_PROP_FRAME_HEIGHT));

    namedWindow("Labeling", 1);
    bool loop = true;
    bool playing = false;
    double nextFrame = 0.0;
    int img_nbr = 0;
    while (loop) {
        Mat frame;
        Mat img;
        cap >> frame;
        resize(frame, img, Size(label_img_width, label_img_height));
        imshow("Labeling", img);

        std::stringstream ss;
        int wait_time = 1000 / 30;
        if (!playing) wait_time = 0; // forever
        int key = waitKeyEx(wait_time);
        switch (key) {
            case SPACE_KEY:
                playing = !playing;
                break;
            case Q_KEY:
                loop = false;
                break;
            case S_KEY:
                ss << OutputFolder << "/" << img_nbr++ << ".png";
                imwrite(ss.str().c_str(), img);
                break;
            case ARROW_LEFT_KEY:
                nextFrame = cap.get(cv::CAP_PROP_POS_FRAMES);
                if (!cap.set(cv::CAP_PROP_POS_FRAMES, nextFrame - 2.0)) {
                    std::cout << "can´t access previous frame" << std::endl;
                }
                break;
            case ARROW_RIGHT_KEY:
                break; // next frame gets fetched automatically
        }
    }

    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}