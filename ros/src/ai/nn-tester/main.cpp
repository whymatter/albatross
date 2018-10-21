#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>
#include <thread>
#include <chrono>

#define OPENCV

#include "yolo_v2_class.hpp"    // imported functions from DLL

#ifdef OPENCV

#include <opencv2/opencv.hpp>            // C++
#include "opencv2/core/version.hpp"

#ifndef CV_VERSION_EPOCH

#include "opencv2/videoio/videoio.hpp"

#pragma comment(lib, "opencv_world320.lib")
#else
#pragma comment(lib, "opencv_core2413.lib")
#pragma comment(lib, "opencv_imgproc2413.lib")
#pragma comment(lib, "opencv_highgui2413.lib")
#endif

class FrameProvider {
public:
    virtual cv::Mat next_frame() = 0;

    virtual bool has_frame() { return true; }

    virtual bool show_result(cv::Mat const &mat_img) = 0;
};

class ImageProvider : public FrameProvider {
public:
    explicit ImageProvider(std::vector<std::string> &image_file_names, std::vector<std::string>::iterator &it)
            : image_file_names_(image_file_names), image_iterator_(it) {
        //this->image_iterator_ = image_file_names.begin();
    }

    cv::Mat next_frame() override {
        if (this->image_iterator_ == this->image_file_names_.end()) {
            return cv::Mat();
        }

        std::string file = *(this->image_iterator_);
        ++this->image_iterator_;
        std::cout << "input image filename: " << file << std::endl;
        return cv::imread(file);
    }

    bool has_frame() override { return this->image_iterator_ != this->image_file_names_.end(); }

    bool show_result(cv::Mat const &mat_img) override {
        cv::imshow("Image", mat_img);
        return cv::waitKey(0) == 0x71;
    }

private:
    std::vector<std::string>::iterator &image_iterator_;
    std::vector<std::string> &image_file_names_;
};

class VideoProvider : public FrameProvider {
public:
    explicit VideoProvider(cv::VideoCapture& cap) : video_capture_(cap) {
        this->video_capture_.set(CV_CAP_PROP_FRAME_WIDTH, 640);
        this->video_capture_.set(CV_CAP_PROP_FRAME_HEIGHT, 360);
    }

    cv::Mat next_frame() override {
        cv::Mat frame;
        this->video_capture_ >> frame;
        if (frame.empty()) {
            frame = this->last_frame_;
            this->has_frame_ = false;
        } else {
            this->last_frame_ = frame;
        }

        return frame;
    }

    bool has_frame() override { return this->has_frame_; }

    bool show_result(cv::Mat const &mat_img) override {
        auto now = std::chrono::high_resolution_clock::now();
        std::stringstream s;
        s << 1000.0 / std::chrono::duration_cast<std::chrono::milliseconds>(now - this->last_start).count();
        last_start = now;
        cv::putText(mat_img, s.str(), cv::Point(100, 100), cv::FONT_HERSHEY_SIMPLEX, 1, cv::Scalar(0, 0, 255));
        cv::imshow("Webcam", mat_img);
        return cv::waitKey(1) == 0x71;
    }

private:
    cv::VideoCapture& video_capture_;
    std::chrono::time_point<std::chrono::high_resolution_clock> last_start;
    cv::Mat last_frame_;
    bool has_frame_ = true;
};

cv::Mat draw_boxes(cv::Mat mat_img, std::vector<bbox_t> result_vec, std::vector<std::string> obj_names) {
    for (auto &i : result_vec) {
        cv::Scalar color(60, 160, 260);
        cv::rectangle(mat_img, cv::Rect(i.x, i.y, i.w, i.h), color, 3);
        if (obj_names.size() > i.obj_id)
            putText(mat_img, obj_names[i.obj_id], cv::Point2f(i.x, i.y - 10), cv::FONT_HERSHEY_COMPLEX_SMALL, 1, color);
        if (i.track_id > 0)
            putText(mat_img, std::to_string(i.track_id), cv::Point2f(i.x + 5, i.y + 15), cv::FONT_HERSHEY_COMPLEX_SMALL,
                    1, color);
    }

    return mat_img;
}

#endif    // OPENCV


void show_result(std::vector<bbox_t> const result_vec, std::vector<std::string> const obj_names) {
    for (auto &i : result_vec) {
        if (obj_names.size() > i.obj_id) std::cout << obj_names[i.obj_id] << " - ";
        std::cout << "obj_id = " << i.obj_id << ",  x = " << i.x << ", y = " << i.y
                  << ", w = " << i.w << ", h = " << i.h
                  << std::setprecision(3) << ", prob = " << i.prob << std::endl;
    }
}

std::vector<std::string> objects_names_from_file(std::string const filename) {
    std::ifstream file(filename);
    std::vector<std::string> file_lines;
    if (!file.is_open()) return file_lines;
    for (std::string line; file >> line;) file_lines.push_back(line);
    std::cout << "object names loaded \n";
    return file_lines;
}

std::string get_names_file_name(const std::string &data_file_name) {
    std::ifstream data_file(data_file_name);
    std::string key, equality_char, names_file_name;
    while (data_file >> key >> equality_char >> names_file_name && key != "names");

    if (key != "names") {
        std::cout << "no names file found" << std::endl;
        return nullptr;
    }

    return names_file_name;
}

std::vector<std::string> image_names_from_file(const std::string &image_list_file_name) {
    std::ifstream image_list_file(image_list_file_name);
    std::vector<std::string> image_list;
    std::string line;
    while (std::getline(image_list_file, line)) image_list.push_back(line);
    return image_list;
}

int main(int argc, char **argv) {
    if (argc != 5) {
        std::cout << "./nn-tester [.data] [.cfg] [.weights] [.txt|cam]" << std::endl;
        return -1;
    }

    std::string names_file_name = get_names_file_name(std::string(argv[1]));
    std::cout << "names file: " << names_file_name << std::endl;

    auto obj_names = objects_names_from_file(names_file_name);

    std::string file_or_cam(argv[4]);
    FrameProvider *frame_provider;

    std::vector<std::string> image_names;
    std::vector<std::string>::iterator image_names_it;
    cv::VideoCapture cap;


    if (file_or_cam == "cam") {
        cap = cv::VideoCapture(0);
        frame_provider = new VideoProvider(cap);
    } else if (file_or_cam.compare(file_or_cam.length()-3, 4, ".mp4")) {
        cap = cv::VideoCapture(file_or_cam);
        frame_provider = new VideoProvider(cap);
    } else {
        image_names = image_names_from_file(file_or_cam);
        image_names_it = image_names.begin();
        frame_provider = new ImageProvider(image_names, image_names_it);
    }

    cv::Mat first_frame = frame_provider->next_frame();

    auto writer = cv::VideoWriter("/home/whymatter/albatross/drive-processed-001.mp4", cv::VideoWriter::fourcc('m', 'p', '4', 'v'), 30.0, cv::Size(640, 360));

    Detector detector(argv[2], argv[3]);

    cv::Mat next_frame;
    while (frame_provider->has_frame()) {
        next_frame = frame_provider->next_frame();
        cv::Mat resized_frame;
        cv::resize(next_frame, resized_frame, cv::Size(640, 360));
        next_frame = resized_frame;
        try {
            std::vector<bbox_t> result_vec = detector.detect(next_frame);
            cv::Mat mat_img = draw_boxes(next_frame, result_vec, obj_names);
            bool exit = frame_provider->show_result(mat_img);
            show_result(result_vec, obj_names);
            writer << mat_img;
            if (exit) {
                writer.release();
                break;
            }
        }
        catch (std::exception &e) {
            std::cerr << "exception: " << e.what() << "\n";
            getchar();
        }
        catch (...) {
            std::cerr << "unknown exception \n";
            getchar();
        }
    }

    return 0;
}