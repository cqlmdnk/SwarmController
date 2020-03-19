#pragma once
#include "ImageFetch.h"



class ContourArea
{
public:
	ContourArea();
	~ContourArea();
	uint8_t contourSpec[3];
	static double * extractContours(string droneId, string args[], int im_size[2]);
	static bool * getAvaiableDirections(string droneId);
};

