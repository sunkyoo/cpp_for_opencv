#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	Mat dst = 255 - src;

	Rect rc(100, 150, 300, 200);
	Mat crop = src(rc);

	imshow("src", src);
	imshow("dst", dst);
	imshow("crop", crop);

	waitKey(0);
	return 0;
}
