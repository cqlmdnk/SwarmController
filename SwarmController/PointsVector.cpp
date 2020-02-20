#include "PointsVector.h"
std::vector<Point> PointsVector::pointsOnThreads;
bool PointsVector::flagsOnThreads[100];
std::condition_variable PointsVector::cvr;
std::mutex PointsVector::mtx[100];
std::mutex PointsVector::t_mtx;
msr::airlib::MultirotorRpcLibClient PointsVector::client;

PointsVector::PointsVector()
{
}
