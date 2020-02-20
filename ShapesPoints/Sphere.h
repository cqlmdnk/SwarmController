#pragma once
#include "Point.h"
#include "Points.h"
class Sphere : public Points
{
	Sphere();
	~Sphere();
	virtual std::vector<Point> getPoints(int size);
};

