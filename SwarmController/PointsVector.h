#pragma once
#include <vector>
#include "../ShapesPoints/Point.h"
#include <condition_variable>
#include <mutex>
class PointsVector
{
public:
	static std::condition_variable cvr;
	static std::mutex mtx[100];
	static std::vector<Point> pointsOnThreads;
	static bool flagsOnThreads[100];
	PointsVector();
};

