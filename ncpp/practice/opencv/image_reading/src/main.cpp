// main file

#include <iostream>
#include <opencv2/opencv.hpp>

int main(int argc, char **argv) {
	cv::Mat img;
	std::string path = "../test_img.jpg";
	//std::cout << "Enter the path of image file: " << std::endl;
	//std::cin >> path;
	img = cv::imread(path, cv::IMREAD_COLOR);
	cv::namedWindow("Display Image", cv::WINDOW_AUTOSIZE);
	cv::imshow("Display Image", img);
	cv::waitKey(0);
	return 0;
}