
#include "easypr.h"
#include <iostream>
using namespace easypr;

// author: Lizinuo
void resolution(char *filename)
{
    CPlateRecognize pr;
    pr.setResultShow(true);
    pr.setDetectType(PR_DETECT_CMSER | PR_DETECT_SOBEL);
    pr.setMaxPlates(5);
    vector<CPlate> plateVec;
    Mat src = imread(filename);
    int result = pr.plateRecognize(src, plateVec);
    if (result != 0)
    {
        cout << "Failed!" << endl;
        return;
    }
    else
    {
        cout << plateVec.size() << " Results" << endl;
    }
    namedWindow(filename, WINDOW_AUTOSIZE);
    for (int i = 0; i < plateVec.size(); i++)
    {
        CPlate plate = plateVec.at(i);
        Mat plateMat = plate.getPlateMat();

        imshow(filename, plateMat);
        waitKey(0);
        string license = plate.getPlateStr();
        cout << license << endl;
    }
    destroyWindow(filename);
    return;
}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        resolution(argv[i]);
    }
}