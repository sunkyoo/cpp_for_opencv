#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);

	Ptr<Feature2D> detector = ORB::create();
//	Ptr<Feature2D> detector = KAZE::create();

	vector<KeyPoint> keypoints;
	detector->detect(src, keypoints);

	Mat dst;
	drawKeypoints(src, keypoints, dst);

	imshow("src", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;
}