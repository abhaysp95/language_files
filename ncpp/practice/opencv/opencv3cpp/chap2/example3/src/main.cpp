// main file

#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char **argv) {
	cv::namedWindow("Example3", cv::WINDOW_AUTOSIZE);
	cv::VideoCapture cap;
	cap.open(std::string(argv[1]));

	cv::Mat frame;
	while (true) {
		cap >> frame;
		if (frame.empty()) {
			// if ran out of film
			break;
		}
		cv::imshow("Example3", frame);
		if (cv::waitKey(10) >= 0) {
			std::cout << "due to waitKey" << std::endl;
			break;
		}
	}
	return 0;
}