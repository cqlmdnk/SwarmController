#pragma once


#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include "PointsVector.h"
#include "Eigen/Eigen"
using namespace Eigen;
class Collision
{
public:
	static bool* getAvailDirs(string name);
	static Vector3f getManeVec(msr::airlib::string name, Vector3f unitTargetVec, float yaw);
};

