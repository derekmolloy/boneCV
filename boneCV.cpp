#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main()
{
    VideoCapture capture(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH,1920);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT,1080);
    if(!capture.isOpened()){
	    cout << "Failed to connect to the camera." << endl;
    }
    Mat frame, edges;
    capture >> frame;
    if(frame.empty()){
		cout << "Failed to capture an image" << endl;
		return -1;
    }
    cvtColor(frame, edges, CV_BGR2GRAY);
    Canny(edges, edges, 0, 30, 3);
    imwrite("edges.png", edges);
    imwrite("capture.png", frame);
    return 0;
}
