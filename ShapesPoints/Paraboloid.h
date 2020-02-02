#pragma once
#include "Point.h"
#include "Points.h"
class Paraboloid : public Points
{
public:
	Paraboloid();
	~Paraboloid();
	virtual std::vector<Point> getPoints();
};

