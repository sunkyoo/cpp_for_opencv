#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

void on_trackbar(int p, void*)
{
	cout << "trackbar1: " << p << endl;
}

int main(void)
{
	Mat src = imread("lenna.bmp", IMREAD_GRAYSCALE);
	imshow("src", src);

	createTrackbar("trackbar1", "src", 0, 100, on_trackbar);
	createTrackbar("trackbar2", "src", 0, 100, [](int p, void* userdata) {
		Mat src = *(Mat*)userdata;
		Mat dst = src + p;
		imshow("src", dst);
		cout << "trackbar2: " << p << endl;
		}, (void*)&src);

	waitKey(0);
	return 0;
}
