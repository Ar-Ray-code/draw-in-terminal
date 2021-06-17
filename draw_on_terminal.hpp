#ifndef draw_on_terminal_hpp
#define draw_on_terminal_hpp

#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstring>
#include <math.h>

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <random>
#include <time.h>

using namespace std;

#define BACKGROUND  0
#define NUMBER      1

#define DISABLE     0
#define ENABLE      1

class draw_terminal:public cv::VideoCapture
{
    private:
        void print_help();
        void video(const char* video_name);
        void picture(const char* img_name);
        void select_mode(const char* command);
        void draw(cv::Mat img);


        bool color;
        bool random_num;
        bool number_view;
        bool gray;

        char command[11];
        struct winsize w;
        cv::Mat img_data;
        cv::Mat gray_data;
        cv::Vec3b bgr;
        char command_str[100];

    public:
        draw_terminal(int _argc, const char** _argv);
        ~draw_terminal();
};
#endif