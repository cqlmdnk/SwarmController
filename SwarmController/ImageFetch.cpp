#include "ImageFetch.h"


ImageFetch::ImageFetch(string droneId, int size[])
{
	this->droneId = droneId;
	this->size = size;
}

ImageFetch::ImageFetch(ImageFetch &&)
{
}


ImageFetch::~ImageFetch()
{
}

Mat ImageFetch::returnImage(string cameraName) //COK YAVASSSSS!!!
{
	//client can be passed as argument
	msr::airlib::vector<ImageCaptureBase::ImageRequest> request;
	request.push_back(ImageCaptureBase::ImageRequest(cameraName, ImageType::DepthPlanner, true, false));
	msr::airlib::vector < ImageCaptureBase::ImageResponse> response;
	auto start = chrono::steady_clock::now();

	// do some stuff here

	

	while (response.empty()) // check that the rows and cols match the size of your vector
	{
		response = client.simGetImages(request, droneId);
	}
	auto end = chrono::steady_clock::now();

	cout << "Request Elapsed time in nanoseconds : "
		<< chrono::duration_cast<chrono::nanoseconds>(end - start).count()
		<< " ns" << endl;
	msr::airlib::vector<float> floatData = response.at(0).image_data_float;

	Mat src = Mat(80, 80, CV_32FC1);
	memcpy(src.data, floatData.data(), floatData.size() * sizeof(float));

	return src;

	// change uchar to any type of data values that you want to use instead

// convert image to given format
// change upper control for given size just copy data to image from depth
//then change resolution of MAt image


}


