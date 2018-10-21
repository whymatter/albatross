//
// Created by whymatter on 15.09.18.
//

#include "node.h"
#include "opencv2/opencv.hpp"

using namespace cv;

int main(int argc, char **argv) {

    Mat img = imread("/home/whymatter/img.png");

    Mat contours;
    Mat hier;
    findContours(img, contours, hier, RetrievalModes::RETR_TREE, ContourApproximationModes::CHAIN_APPROX_SIMPLE);

    imshow("img", img);

    waitKey(0);

    return 0;
}