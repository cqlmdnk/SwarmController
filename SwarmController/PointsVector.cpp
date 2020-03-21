#include "PointsVector.h"
std::vector<Eigen::Vector3f> PointsVector::pointsOnThreads;


msr::airlib::MultirotorRpcLibClient PointsVector::client;

Eigen::Vector3f PointsVector::swarmCenter;
std::queue<Eigen::Vector3f> PointsVector::waypoints;
float PointsVector::totalDistance;
PointsVector::PointsVector()
{
	PointsVector::swarmCenter = Eigen::Vector3f(0.0f, 0.0f, 0.0f);
}
