

/*This is the Opencv code can be used for taking real time stream from Logitech C110 camera without undergoing the select timeout error 
Usually takes place while fetching real time frames using C110. The frame width and Height specified are one of the most optimal solutions
  of the problem.*/
#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int main()
{
VideoCapture cap;
cap.open(0);
Mat a;
//Add these two lines in your code to avoid running into select timeout error
cap.set(CV_CAP_PROP_FRAME_WIDTH,450);//1
cap.set(CV_CAP_PROP_FRAME_HEIGHT,500);//2
while(1)
{
cap>>a;
imshow("  ",a);
waitKey(1);
}
return 0;
}
