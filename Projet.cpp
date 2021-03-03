#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

void main(int argc, char** argv)
{
	string path = "Ressources/homme.png";
	Mat img = imread(path);

	CascadeClassifier faceCascade;	//chargement de la cascade
	faceCascade.load("Ressources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not loaded" << endl; } //facultatif : permet de vérifier que le fichier cml est bien chargé

	vector<Rect> faces;
	faceCascade.detectMultiScale(img, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++)
	{
		rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
	}

	while (true)
	{
		imshow("image", img);
		waitKey(1);
	}
}