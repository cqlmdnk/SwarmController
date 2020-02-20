#pragma once
#include <vector>
#include "../ShapesPoints/Point.h"
#include <condition_variable>
#include <mutex>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"

class PointsVector
{
public:
	static std::condition_variable cvr;
	static std::mutex mtx[100];
	static std::mutex t_mtx;
	static std::vector<Point> pointsOnThreads;
	static bool flagsOnThreads[100];
	static msr::airlib::MultirotorRpcLibClient client;
	PointsVector();
};

