#pragma once
#include "Points.h"
class VFormation :
	public Points
{
public:
	VFormation();
	~VFormation();
	virtual std::vector<Point> getPoints(int size);
	std::vector<Point> obtainPoints(float factor, int x, int y, float z_begin, float z_end);
	void normalizeVectors(RowVectorXf& upper, RowVectorXf& lower);
	void mirrorPoints(std::vector<Point>& returnPoints);
};
