// main file

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
	/* imread() is high-level routine that determines the file format to be loaded based on the filename, it also automatically allocates the memory needed for the image data structure */
	cv::Mat img = cv::imread(argv[1], -1);
	if (img.empty()) {
		return -1;
	}
	cv::namedWindow("Example1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example1", img);
	cv::waitKey(0);
	cv::destroyWindow("Example1");
	return 0;
}