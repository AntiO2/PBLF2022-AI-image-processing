#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using std::cout;
using std::endl;
int main(int argv, char **argc)
{
    if (argv != 2)
    {
        cout << "NO PATH" << endl;
        return 0;
    }
    namedWindow("Video_test", 960 * 540);
    VideoCapture cap;
    cap.open(argc[1]);
    Mat frame;
    for (;;)
    {
        cap >> frame;
        if (frame.empty())
            break;
        imshow("Lizn", frame);
        if (waitKey(33) >= 0)
            break;
    }
    return 0;
}