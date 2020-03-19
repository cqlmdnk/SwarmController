#include "VFormation.h"


VFormation::VFormation() : Points()
{

}

VFormation::~VFormation()
{

}





std::vector<Vector3f> VFormation::getPoints(int size , int scale = 10)
{
	std::vector<Vector3f> returnPoints;

	VectorXf VectorXDomain = VectorXf(int(size/4));
	VectorXDomain.setLinSpaced(int(size / 4), 0, scale*2);

	VectorXf Vector300fUpper = VectorXf(int(size / 4));
	VectorXf Vector300fLower = VectorXf(int(size / 4));

	// vformation formulas


	Vector300fLower = 2*((VectorXDomain.array())+8).matrix();
	Vector300fUpper = 2*(2*(VectorXDomain.array()+8)).matrix();

	

	//VFormation::normalizeVectors(Vector300fLower, Vector300fUpper);


	float factor = 0.1f;
	do {
		factor += 0.1f;
		returnPoints.clear();
		for (int i = 0; i < Vector300fUpper.rows(); i++)
		{
			std::vector<Vector3f> obtainedPoints = VFormation::obtainPoints(factor, i*4, -10, Vector300fLower(i,0), Vector300fUpper(i,0));
			returnPoints.insert(std::end(returnPoints), std::begin(obtainedPoints), std::end(obtainedPoints));
			obtainedPoints.clear();
			
		}
		
	} while ((size/2 < returnPoints.size()));
	VFormation::mirrorPoints(returnPoints, (Vector300fUpper.rows()-1)*4);
	return returnPoints;
}

std::vector<Vector3f> VFormation::obtainPoints(float factor, int x, int z, float y_begin, float y_end) {
	std::vector<Vector3f> obtainedPoints;

	int pointsCount = int(abs((y_begin - y_end) / factor));
	if (pointsCount == 0 && y_begin != y_end) {
		obtainedPoints.push_back(Vector3f(x,(y_begin + y_end) / 2, z-10));
		return obtainedPoints;
	}

	for (int i = 0; i < pointsCount; i++) {

		obtainedPoints.push_back(Vector3f(x, (y_begin + i * factor), z-10));
	}

	return obtainedPoints;

}

void VFormation::normalizeVectors(RowVectorXf& upper, RowVectorXf& lower) {

	
	double upperMin = upper.minCoeff();
	double lowerMin = lower.minCoeff();


	if (upperMin < lowerMin) {
		lower = (lower.array() - upperMin);
		upper = (upper.array() - upperMin);
	}
	else {
		lower = (lower.array() - lowerMin);
		upper = (upper.array() - lowerMin);
	}
	double nupperMin = upper.minCoeff();
	double nlowerMin = lower.minCoeff();
	if (nupperMin < nlowerMin) {
		lower = (lower.array() / nlowerMin);
		upper = (upper.array() / nlowerMin);
	}
	else {
		lower = (lower.array() / nupperMin);
		upper = (upper.array() / nupperMin);
	}

	lower = (lower.array() * 10);
	upper = (upper.array() * 10);


	
}

void VFormation::mirrorPoints(std::vector<Vector3f>& returnPoints, int rowCount) {
	for (auto point : returnPoints) {
		returnPoints.push_back(Vector3f(-point.x()+1+2*rowCount, point.y(), point.z()));
		
	}
	for (auto point : returnPoints) {
		std::cout << std::to_string(point.x()) + " , " + std::to_string(point.y()) + " , " + std::to_string(point.z()) << std::endl;
	}
	int c = 0;
}