// main file

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>

int main(int argc, char **argv) {
	cv::Mat image = cv::imread("test_img.jpg");

	cv::Mat gray;
	cv::cvtColor(image, gray, cv::COLOR_RGB2GRAY);

	cv::Mat edges;
	cv::Canny(blurred, edges, 100, 200);

	std::vector<std::vector<cv::Point>> contours;
	cv::findContours(edges, contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

	for (size_t i = 0; i < contours.size(); ++i) {
		cv::drawContours(image, contours, static_cast<int>(i), CV_RGB(255, 0, 0), 2);
	}

	cv::imshow("contours", image);
	cv::waitKey();
	return 0;
}