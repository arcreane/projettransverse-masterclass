#include "fonctions.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void test_camera()
{

    VideoCapture stream1(0);   //0 is the id of video device.0 if you have only one camera.

    if (!stream1.isOpened()) { //check if video device has been initialised
        cout << "cannot open camera";
    }

    //unconditional loop
    while (true) {
        Mat cameraFrame;
        stream1.read(cameraFrame);
        imshow("cam", cameraFrame);
        if (waitKey(30) >= 0)
            break;
    }

}