#include "PointsVector.h"
std::vector<Eigen::Vector3f> PointsVector::pointsOnThreads;


msr::airlib::MultirotorRpcLibClient PointsVector::client;

PointsVector::PointsVector()
{
}
