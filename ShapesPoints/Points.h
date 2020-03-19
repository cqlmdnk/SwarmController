#pragma once
#include <vector>
#include "PLocal.h"
#include "include/Eigen/Dense"
#include <ctime>
#include <cmath>

#define PARAB 0
#define CIRC 1
#define SPHE 2
#define VFOR 3


using namespace Eigen;
class Points
{

public:
	MatrixXf Matrix300f = MatrixXf(11,11); // move to base class constructor if it's possible
	RowVectorXf Vector300f = RowVectorXf(11);
	Points();
	virtual std::vector<Vector3f> getPoints(int size, int scale) = 0;
	void normalizeMatrices(MatrixXf& upper, MatrixXf& lower);
	double floorUnry(double x);
	
};

