#include <imgcodecs.hpp>
#include <highgui.hpp>
#include <imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void main()
{
	VideoCapture cap(0); // le 0 correspond à la webcame 0 de son ordinateur
	Mat img;

	while(true)
	{
		cap.read(img);

		imshow("image", img);
		waitkey(1);
	}
}