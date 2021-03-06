#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;
using namespace cv;
using namespace std;

void main(int argc, char** argv)
{
<<<<<<< HEAD

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


=======
	VideoCapture cap(0); // le 0 correspond à la webcame 0 de son ordinateur
	Mat img;

	while (true)
	{
		cap.read(img);

		imshow("image", img);
		waitkey(1);
	}
>>>>>>> detection_de_visage_image_fixe
}