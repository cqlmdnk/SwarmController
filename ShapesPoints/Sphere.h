#pragma once
#include "PLocal.h"
#include "Points.h"
class Sphere : public Points
{
public:
	Sphere();
	~Sphere();
	virtual std::vector<Vector3f> getPoints(int size, int scale);
};

