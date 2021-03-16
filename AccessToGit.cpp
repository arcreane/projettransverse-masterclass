#include "opencv2/objdetect.hpp" 
#include "opencv2/highgui.hpp" 
#include "opencv2/imgproc.hpp"

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>

#include "opencv2/highgui/highgui.hpp"
#include <iostream> 
#include <opencv2/core/types_c.h>

using namespace std;
using namespace cv;

// Function for Face Detection 
void detectAndDraw(Mat& img, CascadeClassifier& cascade,
    CascadeClassifier& nestedCascade, double scale);
string cascadeName, nestedCascadeName;
void CallBackFunc(int event, int x, int y, int flags, void* userdata);

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
    if (event == EVENT_LBUTTONDOWN)
    {
        cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_RBUTTONDOWN)
    {
        cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MBUTTONDOWN)
    {
        cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
    }
    else if (event == EVENT_MOUSEMOVE)
    {
        cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

    }
}

int main(int argc, const char** argv)
{
    // VideoCapture class for playing video for which faces to be detected 
    VideoCapture capture;
    Mat frame, image;

    // PreDefined trained XML classifiers with facial features 
    CascadeClassifier cascade, nestedCascade;
    double scale = 1;

    // Load classifiers from "opencv/data/haarcascades" directory  

    bool load = nestedCascade.load("\\out\\bin\Debug\\haarcascade_eye_tree_eyeglasses.xml");

    // Change path before execution  
    cascade.load("\\out\\bin\\Debug\\haarcascade_frontalcatface.xml");

    // Start Video..1) 0 for WebCam 2) "Path to Video" for a Local Video 

    capture.open(0);
    if (capture.isOpened())
    {
        // Capture frames from video and detect faces 
        cout << "Face Detection Started...." << endl;
        while (1)
        {
            capture >> frame;
            if (frame.empty())
                break;
            Mat frame1 = frame.clone();
            detectAndDraw(frame1, cascade, nestedCascade, scale);
            char c = (char)waitKey(10);

            // Utilisation des touches du clavier
            if (c == 27 || c == 'q' || c == 'Q') {
                cout << "Touche Q pour quitter" << endl;
                break;
            }
            else if (c == 27 || c == 'd' || c == 'D') {
                cout << "Touche D" << endl;
            }
            else if (c == 27 || c == 's' || c == 'S') {
                cout << "Touche S" << endl;
            }

        }

    }
    else
        cout << "Could not Open Camera";

    setMouseCallback("My Window", CallBackFunc, NULL);
    waitKey(0);
    return 0;
}

void detectAndDraw(Mat& img, CascadeClassifier& cascade,
    CascadeClassifier& nestedCascade,
    double scale)
{
    vector<Rect> faces, faces2;
    Mat gray, smallImg;

    cvtColor(img, gray, COLOR_BGR2GRAY); // Convert to Gray Scale 
    double fx = 1 / scale;

    // Resize the Grayscale Image  
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR);
    equalizeHist(smallImg, smallImg);

    // Detect faces of different sizes using cascade classifier  
    cascade.detectMultiScale(smallImg, faces, 1.1,
        2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

    // Draw circles around the faces 
    for (size_t i = 0; i < faces.size(); i++)
    {
        Rect r = faces[i];
        Mat smallImgROI;
        vector<Rect> nestedObjects;
        Point center;
        Scalar color = Scalar(0, 0, 255); // Color for Drawing tool 
        int radius;

        double aspect_ratio = (double)r.width / r.height;
        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
        {
            center.x = cvRound((r.x + r.width * 0.5) * scale);
            center.y = cvRound((r.y + r.height * 0.5) * scale);
            radius = cvRound((r.width + r.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
        else
            rectangle(img, cvPoint(cvRound(r.x * scale), cvRound(r.y * scale)),
                cvPoint(cvRound((r.x + r.width - 1) * scale),
                    cvRound((r.y + r.height - 1) * scale)), color, 3, 8, 0);
        if (nestedCascade.empty())
            continue;
        smallImgROI = smallImg(r);

        // Detection of eyes int the input image 
        nestedCascade.detectMultiScale(smallImgROI, nestedObjects, 1.1, 2,
            0 | CASCADE_SCALE_IMAGE, Size(30, 30));

        // Draw circles around eyes 
        for (size_t j = 0; j < nestedObjects.size(); j++)
        {
            Rect nr = nestedObjects[j];
            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
            radius = cvRound((nr.width + nr.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
    }


    // Show Processed Image with detected faces 
    imshow("Face Detection", img);
}