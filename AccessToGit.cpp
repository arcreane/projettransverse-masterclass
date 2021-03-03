#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
int main(int argc, char** argv)
{

    VideoCapture stream1(0);   

    if (!stream1.isOpened()) { 
        cout << "cannot open camera";
    }


    while (true) {
        Mat cameraFrame;
        stream1.read(cameraFrame);
        imshow("cam", cameraFrame);
        if (waitKey(30) >= 0)
            break;
    }
    return 0;


}