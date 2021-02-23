#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main(int argc, char** argv)
{
	VideoCapture cap(0); // le 0 correspond à la webcame 0 de son ordinateur. Source de la caméra
	Mat img;

	while (true)
	{
		cap.read(img);

		imshow("image", img);
		waitKey(1);
	}
}