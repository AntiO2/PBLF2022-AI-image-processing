#include <opencv2/opencv.hpp>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
		cout << "No Image File Input" << endl;

	Mat img = imread(argv[1]);
	if (img.empty())
	{
		cout << "Can't Find Image!" << endl;
		return -1;
	}

	namedWindow("Image_test", WINDOW_AUTOSIZE);
	imshow("Image_test", img);
	waitKey(0);
	destroyWindow("Image_test");

	return 0;
}
