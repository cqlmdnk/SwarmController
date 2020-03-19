#pragma once
#include "Points.h"
class VFormation :
	public Points
{
public:
	VFormation();
	~VFormation();
	virtual std::vector<Vector3f> getPoints(int size, int scale);
	std::vector<Vector3f> obtainPoints(float factor, int x, int y, float z_begin, float z_end);
	void normalizeVectors(RowVectorXf& upper, RowVectorXf& lower);
	void mirrorPoints(std::vector<Vector3f>& returnPoints, int rowCount);
};
