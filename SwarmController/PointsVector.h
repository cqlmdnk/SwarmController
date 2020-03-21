#pragma once
#include "../ShapesPoints/PLocal.h"
#include <vector>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <queue>

class PointsVector
{
public:
	static std::vector<Eigen::Vector3f> pointsOnThreads;
	static msr::airlib::MultirotorRpcLibClient client;
	static Eigen::Vector3f swarmCenter;
	static std::queue<Eigen::Vector3f> waypoints;
	static float totalDistance;
	PointsVector();
};

