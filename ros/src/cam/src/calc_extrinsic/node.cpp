//
// Created by whymatter on 15.09.18.
//

#include "intrinsic_parameters.h"
#include "opencv2/opencv.hpp"
#include <iostream>

/**
 *  \brief Automatic brightness and contrast optimization with optional histogram clipping
 *  \param [in]src Input image GRAY or BGR or BGRA
 *  \param [out]dst Destination image
 *  \param clipHistPercent cut wings of histogram at given percent tipical=>1, 0=>Disabled
 *  \note In case of BGRA image, we won't touch the transparency
*/
void BrightnessAndContrastAuto(const cv::Mat &src, cv::Mat &dst, float clipHistPercent=0)
{

    CV_Assert(clipHistPercent >= 0);
    CV_Assert((src.type() == CV_8UC1) || (src.type() == CV_8UC3) || (src.type() == CV_8UC4));

    int histSize = 256;
    float alpha, beta;
    double minGray = 0, maxGray = 0;

    //to calculate grayscale histogram
    cv::Mat gray;
    if (src.type() == CV_8UC1) gray = src;
    else if (src.type() == CV_8UC3) cvtColor(src, gray, CV_BGR2GRAY);
    else if (src.type() == CV_8UC4) cvtColor(src, gray, CV_BGRA2GRAY);
    if (clipHistPercent == 0)
    {
        // keep full available range
        cv::minMaxLoc(gray, &minGray, &maxGray);
    }
    else
    {
        cv::Mat hist; //the grayscale histogram

        float range[] = { 0, 256 };
        const float* histRange = { range };
        bool uniform = true;
        bool accumulate = false;
        calcHist(&gray, 1, 0, cv::Mat (), hist, 1, &histSize, &histRange, uniform, accumulate);

        // calculate cumulative distribution from the histogram
        std::vector<float> accumulator(histSize);
        accumulator[0] = hist.at<float>(0);
        for (int i = 1; i < histSize; i++)
        {
            accumulator[i] = accumulator[i - 1] + hist.at<float>(i);
        }

        // locate points that cuts at required value
        float max = accumulator.back();
        clipHistPercent *= (max / 100.0); //make percent as absolute
        clipHistPercent /= 2.0; // left and right wings
        // locate left cut
        minGray = 0;
        while (accumulator[minGray] < clipHistPercent)
            minGray++;

        // locate right cut
        maxGray = histSize - 1;
        while (accumulator[maxGray] >= (max - clipHistPercent))
            maxGray--;
    }

    // current range
    float inputRange = maxGray - minGray;

    alpha = (histSize - 1) / inputRange;   // alpha expands current range to histsize range
    beta = -minGray * alpha;             // beta shifts current range so that minGray will go to 0

    // Apply brightness and contrast normalization
    // convertTo operates with saurate_cast
    src.convertTo(dst, -1, alpha, beta);

    // restore alpha channel from source
    if (dst.type() == CV_8UC4)
    {
        int from_to[] = { 3, 3};
        cv::mixChannels(&src, 4, &dst,1, from_to, 1);
    }
    return;
}

void lab(cv::Mat src) {

    // READ RGB color image and convert it to Lab
    cv::Mat bgr_image = src;
    cv::Mat lab_image;
    cv::cvtColor(bgr_image, lab_image, CV_BGR2Lab);

    // Extract the L channel
    std::vector<cv::Mat> lab_planes(3);
    cv::split(lab_image, lab_planes);  // now we have the L image in lab_planes[0]

    // apply the CLAHE algorithm to the L channel
    cv::Ptr<cv::CLAHE> clahe = cv::createCLAHE();
    clahe->setClipLimit(4);
    cv::Mat dst;
    clahe->apply(lab_planes[0], dst);

    // Merge the the color planes back into an Lab image
    dst.copyTo(lab_planes[0]);
    cv::merge(lab_planes, lab_image);

    // convert back to RGB
    cv::Mat image_clahe;
    cv::cvtColor(lab_image, image_clahe, CV_Lab2BGR);

    // display the results  (you might also want to see lab_planes[0] before and after).
    cv::imshow("image original", bgr_image);
    cv::imshow("image CLAHE", image_clahe);
    cv::waitKey();

}

int main(int argc, char **argv) {
    cv::namedWindow("preview", 1);

    cv::Mat img = cv::imread("/home/whymatter/Pictures/8/0.png");
    img = cv::imread("/home/whymatter/albatross/training_set_2_1/im/train/cjmnizwel9uqx07260zd97gz5.jpeg");
//    cv::Mat out;
//    BrightnessAndContrastAuto(img, out, 10);
//    cv::imshow("preview", out);
//    cv::waitKey(0);
    lab(img);
    return 0;

    std::vector <cv::Point2d> imagePoints;
    imagePoints.push_back(cv::Point2d(0.6931 * 1000, 0.5779 * 1000));
    imagePoints.push_back(cv::Point2d(0.6948 * 1000, 0.6011 * 1000));
    imagePoints.push_back(cv::Point2d(0.6964 * 1000, 0.6271 * 1000));
    imagePoints.push_back(cv::Point2d(0.6983 * 1000, 0.6562 * 1000));
    imagePoints.push_back(cv::Point2d(0.7008 * 1000, 0.6887 * 1000));
    imagePoints.push_back(cv::Point2d(0.7699 * 1000, 0.5724 * 1000));
    imagePoints.push_back(cv::Point2d(0.7754 * 1000, 0.5947 * 1000));
    imagePoints.push_back(cv::Point2d(0.7817 * 1000, 0.6199 * 1000));
    imagePoints.push_back(cv::Point2d(0.7886 * 1000, 0.6481 * 1000));
    imagePoints.push_back(cv::Point2d(0.7965 * 1000, 0.6799 * 1000));
    imagePoints.push_back(cv::Point2d(0.8450 * 1000, 0.5664 * 1000));
    imagePoints.push_back(cv::Point2d(0.8542 * 1000, 0.5880 * 1000));
    imagePoints.push_back(cv::Point2d(0.8651 * 1000, 0.6127 * 1000));
    imagePoints.push_back(cv::Point2d(0.8767 * 1000, 0.6402 * 1000));
    imagePoints.push_back(cv::Point2d(0.8899 * 1000, 0.6712 * 1000));
    imagePoints.push_back(cv::Point2d(0.9193 * 1000, 0.5599 * 1000));
    imagePoints.push_back(cv::Point2d(0.9324 * 1000, 0.5810 * 1000));
    imagePoints.push_back(cv::Point2d(0.9473 * 1000, 0.6047 * 1000));
    imagePoints.push_back(cv::Point2d(0.9640 * 1000, 0.6315 * 1000));
    imagePoints.push_back(cv::Point2d(0.9824 * 1000, 0.6619 * 1000));
    imagePoints.push_back(cv::Point2d(0.9930 * 1000, 0.5551 * 1000));
    imagePoints.push_back(cv::Point2d(1.0088 * 1000, 0.5756 * 1000));
    imagePoints.push_back(cv::Point2d(1.0286 * 1000, 0.5988 * 1000));
    imagePoints.push_back(cv::Point2d(1.0490 * 1000, 0.6250 * 1000));
    imagePoints.push_back(cv::Point2d(1.0733 * 1000, 0.6540 * 1000));
    imagePoints.push_back(cv::Point2d(1.0644 * 1000, 0.5504 * 1000));
    imagePoints.push_back(cv::Point2d(1.0847 * 1000, 0.5703 * 1000));
    imagePoints.push_back(cv::Point2d(1.1072 * 1000, 0.5930 * 1000));
    imagePoints.push_back(cv::Point2d(1.1323 * 1000, 0.6181 * 1000));
    imagePoints.push_back(cv::Point2d(1.1609 * 1000, 0.6468 * 1000));
    imagePoints.push_back(cv::Point2d(1.1346 * 1000, 0.5457 * 1000));
    imagePoints.push_back(cv::Point2d(1.1579 * 1000, 0.5655 * 1000));
    imagePoints.push_back(cv::Point2d(1.1810 * 1000, 0.5800 * 1000));
    imagePoints.push_back(cv::Point2d(1.1950 * 1000, 0.6010 * 1000));
    imagePoints.push_back(cv::Point2d(1.2136 * 1000, 0.6121 * 1000));

    std::vector <cv::Point3d> worldPoints;
    worldPoints.push_back(cv::Point3d(0, 0, 0));
    worldPoints.push_back(cv::Point3d(0, 42, 0));
    worldPoints.push_back(cv::Point3d(0, 84, 0));
    worldPoints.push_back(cv::Point3d(0, 126, 0));
    worldPoints.push_back(cv::Point3d(0, 168, 0));
    worldPoints.push_back(cv::Point3d(42, 0, 0));
    worldPoints.push_back(cv::Point3d(42, 42, 0));
    worldPoints.push_back(cv::Point3d(42, 84, 0));
    worldPoints.push_back(cv::Point3d(42, 126, 0));
    worldPoints.push_back(cv::Point3d(42, 168, 0));
    worldPoints.push_back(cv::Point3d(84, 0, 0));
    worldPoints.push_back(cv::Point3d(84, 42, 0));
    worldPoints.push_back(cv::Point3d(84, 84, 0));
    worldPoints.push_back(cv::Point3d(84, 126, 0));
    worldPoints.push_back(cv::Point3d(84, 168, 0));
    worldPoints.push_back(cv::Point3d(126, 0, 0));
    worldPoints.push_back(cv::Point3d(126, 42, 0));
    worldPoints.push_back(cv::Point3d(126, 84, 0));
    worldPoints.push_back(cv::Point3d(126, 126, 0));
    worldPoints.push_back(cv::Point3d(126, 168, 0));
    worldPoints.push_back(cv::Point3d(168, 0, 0));
    worldPoints.push_back(cv::Point3d(168, 42, 0));
    worldPoints.push_back(cv::Point3d(168, 84, 0));
    worldPoints.push_back(cv::Point3d(168, 126, 0));
    worldPoints.push_back(cv::Point3d(168, 168, 0));
    worldPoints.push_back(cv::Point3d(210, 0, 0));
    worldPoints.push_back(cv::Point3d(210, 42, 0));
    worldPoints.push_back(cv::Point3d(210, 84, 0));
    worldPoints.push_back(cv::Point3d(210, 126, 0));
    worldPoints.push_back(cv::Point3d(210, 168, 0));
    worldPoints.push_back(cv::Point3d(252, 0, 0));
    worldPoints.push_back(cv::Point3d(252, 42, 0));
    worldPoints.push_back(cv::Point3d(252, 84, 0));
    worldPoints.push_back(cv::Point3d(252, 126, 0));
    worldPoints.push_back(cv::Point3d(252, 168, 0));

    cv::Mat rotation_vector;
    cv::Mat translation_vector;
    cv::solvePnP(worldPoints, imagePoints, intrinsic, distortion, rotation_vector, translation_vector);

    std::cout << "R (default) = " << std::endl << rotation_vector << std::endl;
    std::cout << "T (default) = " << std::endl << translation_vector << std::endl;

    return 0;
}