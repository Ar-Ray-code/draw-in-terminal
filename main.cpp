#include "draw_on_terminal.hpp"

void draw_terminal::print_help()
{
    cout << "help" << endl;
    cout << endl;
    cout << "Summary" << endl << "A joke program that projects an image on the terminal."<< endl;
    cout << endl;
    cout << "Useage" << endl << "If you enter the path of an image or video file after the execution command, that file will be displayed or played."<< endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "--background or -b     : The color display is on the back." << endl;
    cout << "--number or -n         : The color display is a number." << endl;
    cout << "--fixed_value or -f    : The random number of the displayed number is invalidated and the fixed number '8' is output."<< endl;
    cout << "--random_value or -r   : The random number of the displayed number is valid."<< endl;
    cout << "--disable_number or -d : Not display number to draw image." << endl;
    cout << "--gray_enable or -g    : View image by grayscale."<< endl;
}

void draw_terminal::select_mode(const char* command)
{
    if (
        (std::string(command).find(".mp4") != std::string::npos) ||
        (std::string(command).find(".avi") != std::string::npos) ||
        (std::string(command).find(".mjpg") != std::string::npos)
    )
    {
        video(command);
    }
    else if (
        (std::string(command).find(".jpg") != std::string::npos) ||
        (std::string(command).find(".jpe") != std::string::npos) ||
        (std::string(command).find(".jpeg") != std::string::npos) ||
        (std::string(command).find(".JPG") != std::string::npos) ||
        (std::string(command).find(".JPEG") != std::string::npos) ||
        (std::string(command).find(".JPE") != std::string::npos) ||

        (std::string(command).find(".png") != std::string::npos) ||
        (std::string(command).find(".PNG") != std::string::npos) ||

        (std::string(command).find(".bmp") != std::string::npos) ||
        (std::string(command).find(".BMP") != std::string::npos) ||

        (std::string(command).find(".pbm") != std::string::npos) ||
        (std::string(command).find(".pgm") != std::string::npos) ||
        (std::string(command).find(".ppm") != std::string::npos) ||
        (std::string(command).find(".PBM") != std::string::npos) ||
        (std::string(command).find(".PGM") != std::string::npos) ||
        (std::string(command).find(".PPM") != std::string::npos) ||

        (std::string(command).find(".sr") != std::string::npos) ||
        (std::string(command).find(".ras") != std::string::npos) ||
        (std::string(command).find(".SR") != std::string::npos) ||
        (std::string(command).find(".RAS") != std::string::npos) ||

        (std::string(command).find(".tiff") != std::string::npos) ||
        (std::string(command).find(".tif") != std::string::npos) ||
        (std::string(command).find(".TIFF") != std::string::npos) ||
        (std::string(command).find(".TIF") != std::string::npos)
    )
    {
        picture(command);
    }
    else if(std::string(command).find("--") != std::string::npos)
    {
        if(std::string(command).find("help") != std::string::npos)
            print_help();
        if(std::string(command).find("background") != std::string::npos)
            color = BACKGROUND;
        if(std::string(command).find("number") != std::string::npos)
            color = NUMBER;
        if(std::string(command).find("fixed_value") != std::string::npos)
            random_num = DISABLE;
        if(std::string(command).find("random_value") != std::string::npos)
            random_num = ENABLE;
        if(std::string(command).find("disable_number") != std::string::npos)
            number_view = DISABLE;
        if(std::string(command).find("gray_enable") != std::string::npos)
            gray = ENABLE;
    }
    else if(std::string(command).find("-") != std::string::npos)
    {
        if(std::string(command).find("h") != std::string::npos)
            print_help();
        if(std::string(command).find("b") != std::string::npos)
            color = BACKGROUND;
        if(std::string(command).find("n") != std::string::npos)
            color = NUMBER;
        if(std::string(command).find("f") != std::string::npos)
            random_num = DISABLE;
        if(std::string(command).find("r") != std::string::npos)
            random_num = ENABLE;
        if(std::string(command).find("d") != std::string::npos)
            number_view = DISABLE;
        if(std::string(command).find("g") != std::string::npos)
            gray = ENABLE;
    }
    else
    {
        cout << "The command was not recognized. Check if the command is correct. You can also see the options with the --help command."<< endl;
    }
}

void draw_terminal::video(const char* video_name)
{
    this->open(video_name);
    if (!this->isOpened())
    {
        cout << "Can't open video."  << endl;
        exit(-1);
    }

    int rate = this->get(CV_CAP_PROP_FPS);
    unsigned int sleep_time = float(1)/rate*1000*1000;

    for(int frame_all=0; frame_all < this->get(CV_CAP_PROP_FRAME_COUNT) -3;frame_all++)
    {
        this->read(img_data);
        draw(img_data);
        usleep(sleep_time);
    }
}

void draw_terminal::picture(const char* img_name)
{
    img_data = cv::imread(img_name);
    draw(img_data);
}

void draw_terminal::draw(cv::Mat img)
{
    int resized_col, resized_row;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    if(gray)
    {
        cv::cvtColor(img, gray_data, cv::COLOR_BGR2GRAY);
        if(w.ws_col/float(w.ws_row)>1.77)
        {
            resized_col = int( w.ws_col*3);
            resized_row = int(float(img.rows)/img.cols *w.ws_col/2/3);
            cv::resize(gray_data, gray_data, cv::Size(resized_col,resized_row));
        }
        else
        {
            resized_col = int(float(img.cols)/img.rows *w.ws_row*3);
            resized_row = int( w.ws_row/2/3);
            cv::resize(gray_data, gray_data, cv::Size(resized_col,resized_row));
        }
    }
    else
    {
        if(w.ws_col/float(w.ws_row)>1.77)
        {
            resized_col = int( w.ws_col);
            resized_row = int(float(img.rows)/img.cols *w.ws_col/2);
            cv::resize(img_data, img_data, cv::Size(resized_col,resized_row));
        }
        else
        {
            resized_col = int(float(img.cols)/img.rows *w.ws_row);
            resized_row = int( w.ws_row/2);
            cv::resize(img_data, img_data, cv::Size(resized_col,resized_row));
        }
    }
    
    for(int i=0; i<resized_row; i++)
    {
        command_str[0] = '\0';
        for(int j=0; j<resized_col -1; j++)
        {
            int num = random_num ? int(rand()%10) : 8;
            int color_sw = color ? 38 : 48;
            if(gray)    bgr = gray_data.at<cv::Vec3b>(i,j);
            else        bgr = img_data.at<cv::Vec3b>(i,j);
            if(number_view)
                sprintf(command_str,"\033[%d;2;%d;%d;%dm%d",color_sw,int(bgr[2]/8)<<3,int(bgr[1]/8)<<3,int(bgr[0]/8)<<3,num);
            else
                sprintf(command_str,"\033[%d;2;%d;%d;%dm ",color_sw,int(bgr[2]/8)<<3,int(bgr[1]/8)<<3,int(bgr[0]/8)<<3);
            cout << command_str;
        }
        cout << endl;
    }
}

draw_terminal::draw_terminal(int _argc, const char** _argv)
{
    color = NUMBER;
    random_num = ENABLE;
    number_view = ENABLE;
    gray = DISABLE;

	srand(time(NULL));
    for(int i=1;i<_argc;i++)
    {
        select_mode(_argv[i]);
    }
}

draw_terminal::~draw_terminal()
{
    this->release();
}

int main(int argc, const char** argv)
{
    draw_terminal dt(argc, argv);

    return 0;
}


