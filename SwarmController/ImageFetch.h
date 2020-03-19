#pragma once
#include <string>
#include <opencv2/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vehicles/multirotor/api/MultirotorRpcLibClient.hpp>
#include <vector>


typedef ImageCaptureBase::ImageType ImageType;
using namespace cv;
using namespace std;
using namespace msr::airlib;


class ImageFetch
{
public :
	ImageFetch(string droneId, int size[]);
	ImageFetch(ImageFetch &&);
	~ImageFetch();
	Mat returnImage(string cameraName);
protected:
	string droneId;
	Mat image;
	int* size;
	MultirotorRpcLibClient client;
	
};

