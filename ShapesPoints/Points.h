#pragma once
#include <vector>
#include "Point.h"
#include "include/Eigen/Dense"

#define PARAB 0
#define CIRC 1
#define SPHE 2

using namespace Eigen;
class Points
{

public:
	MatrixXf Matrix300f = MatrixXf(11,11); // move to base class constructor if it's possible
	
	RowVectorXf Vector300f = RowVectorXf(11);
	Points();
	virtual std::vector<Point> getPoints(int size) = 0;
};

