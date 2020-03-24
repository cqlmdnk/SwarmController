#pragma once
#include <vector>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <queue>

enum STATE {
	LAND,
	HOVER,
	GO,
	TAKEOFF
};

class PointsVector
{
public:
	static std::vector<Eigen::Vector3f> pointsOnThreads;
	static msr::airlib::MultirotorRpcLibClient client;
	static Eigen::Vector3f swarmCenter;
	static STATE state;
	static std::queue<Eigen::Vector3f> waypoints;
	static float totalDistance;
	static std::vector<Eigen::Vector3f> nodePositions;
	PointsVector();

};

