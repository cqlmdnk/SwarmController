#pragma once
#include <vector>
#include "../ShapesPoints/PLocal.h"
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"

class PointsVector
{
public:
	static std::vector<Eigen::Vector3f> pointsOnThreads;
	static msr::airlib::MultirotorRpcLibClient client;
	PointsVector();
};

