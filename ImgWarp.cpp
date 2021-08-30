#include <opencv2/imgcodecs.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<iostream>

using namespace cv;
using namespace std;



////////////// wrap image /////////

float w = 248, h = 310;
Mat matrix, imgWarp;
void main() {

	string path = "emeka_snipe.jpg";
	Mat img = imread(path);



	Point2f src[4] = { {112,222}, {284,189}, {153,484} ,{353,444} };
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };
	//
	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	for (int i = 0; i < 4; i++)
	{
		circle(img, src[i], 8, Scalar(120, 69, 40), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	waitKey(0);




}