#pragma once
#include "PLocal.h"
#include "Points.h"
class Paraboloid : public Points
{
public:
	Paraboloid();
	~Paraboloid();
	virtual std::vector<Vector3f> getPoints(int size, int scale );
	std::vector<Vector3f> obtainPoints(float factor, int x, int y, float z_begin, float z_end);

};

