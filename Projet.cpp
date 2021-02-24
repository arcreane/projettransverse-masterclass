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
	Mat img, imgGris, imgBlur, imgCanny;

	while (true)
	{
		cap.read(img);

		cvtColor(img, imgGris, COLOR_BGR2GRAY);
		GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
		Canny(imgBlur, imgCanny, 50, 150);


		imshow("Image grise", imgGris); //affiche l'image en noire et blanc
		imshow("image", img); //affiche l'image en couleur sans modification 
		imshow("image Blur", imgCanny); //affiche l'image avec les bords détectés 
		waitKey(1);
	}
}