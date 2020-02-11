#pragma once
#include "Point.h"
#include "Points.h"
class Paraboloid : public Points
{
public:
	Paraboloid();
	~Paraboloid();
	virtual std::vector<Point> getPoints(int size);
	std::vector<Point> obtainPoints(float factor, int x, int y, float z_begin, float z_end);

};

