#include "ContourArea.h"
#include <chrono>
#include <iostream>
ContourArea::ContourArea()
{
}

ContourArea::~ContourArea()
{
}
using namespace std::chrono;
double * ContourArea::extractContours(string droneId, string args[], int im_size[2])
{

	int size = sizeof(args) / sizeof(args[0]);
	double * maxContourAreas = new double[6];

	
	ImageFetch im_fetcher = ImageFetch(droneId, im_size);
	for (size_t i = 0; i < 6; i++)
	{
		auto start = chrono::steady_clock::now();

		// do some stuff here
		Mat image = im_fetcher.returnImage(args[i]);

		auto end = chrono::steady_clock::now();

		cout << "Fetching Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;
		
		 start = chrono::steady_clock::now();
		resize(image, image, cv::Size(80, 80));
		 end = chrono::steady_clock::now();

		cout << "Resize Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;

		// split img:
		// get the channels (dont forget they follow BGR order in OpenCV)

		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		
		

		 start = chrono::steady_clock::now();
		log(image, image);
		 end = chrono::steady_clock::now();

		cout << "Log Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;

		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		start = chrono::steady_clock::now();
		cv::normalize(image, image, 0, 255, cv::NORM_MINMAX);
		end = chrono::steady_clock::now();

		cout << "Normalize Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;

		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		 start = chrono::steady_clock::now();

		image.convertTo(image, CV_8UC1);
		 end = chrono::steady_clock::now();

		cout << "Convert Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;
		 start = chrono::steady_clock::now();
		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		threshold(image, image, 85, 255, THRESH_BINARY);
		 end = chrono::steady_clock::now();

		cout << "Threshold Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;
		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		 start = chrono::steady_clock::now();

		bitwise_not(image, image);
		 end = chrono::steady_clock::now();

		cout << "BitwiseNot Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;
		 start = chrono::steady_clock::now();
		float kdata[] = { 1,1, 1, 1, 1, 1, 1, 1, 1 };
		Mat kernel(3, 3, CV_32F, kdata);
		morphologyEx(image, image, cv::MORPH_CLOSE, kernel, cv::Point(1, 1), 3);
		 end = chrono::steady_clock::now();

		cout << "Closing Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;

		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/threshImg.png", image);
		

		
		
		

		


	
		
		std::vector<std::vector<cv::Point>> _contours;
		 start = chrono::steady_clock::now();

		findContours(image, _contours, RETR_LIST, CHAIN_APPROX_NONE);
		 end = chrono::steady_clock::now();

		cout << "Finding Contours Elapsed time in nanoseconds : "
			<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
			<< " ns" << endl;
		sort(_contours.begin(), _contours.end(), [](const std::vector<Point>& c1, const std::vector<Point>& c2) {
			return contourArea(c1, false) < contourArea(c2, false);
		});
		//drawContours(image, _contours, -1, cv::Scalar(255,255,0),10);
		//cv::imwrite("C:/Users/dell/Desktop/project_proposal/img_process_method/contours.png", image);
		// return contours with maximum area
		// handle if there is no contour
		if (_contours.size() > 0) {
			maxContourAreas[i] = contourArea(_contours[_contours.size() - 1]);
		}
		else
			maxContourAreas[i] = 0;
	}
	return maxContourAreas;
	
}

bool * ContourArea::getAvaiableDirections(string droneId)
{
	bool * availableDirections = new bool[6];
	double * maxContourAreas = new double[6];
	string cameraNames[] = { "front", "back", "left", "right", "top", "bottom" };
	int size[] = { 80,80 };
	maxContourAreas = ContourArea::extractContours(droneId, cameraNames, size);
	for (size_t i = 0; i < 6; i++)
	{
		if (maxContourAreas[i] < 2000.0)
			availableDirections[i] = true;
		else
			availableDirections[i] = false;
	}
	return availableDirections;
	
}


