#include "VFormation.h"


VFormation::VFormation() : Points()
{

}

VFormation::~VFormation()
{

}





std::vector<Point> VFormation::getPoints(int size)
{
	std::vector<Point> returnPoints;

	VectorXf VectorXDomain = VectorXf(21);
	VectorXDomain.setLinSpaced(21, 0, 20);

	VectorXf Vector300fUpper = VectorXf(21);
	VectorXf Vector300fLower = VectorXf(21);

	// vformation formulas

	std::cout << VectorXDomain << std::endl;

	Vector300fLower = 2*((VectorXDomain.array())+8).matrix();
	Vector300fUpper = 2*(2*(VectorXDomain.array()+8)).matrix();

	std::cout << Vector300fLower << std::endl;
	std::cout << Vector300fUpper << std::endl;

	//VFormation::normalizeVectors(Vector300fLower, Vector300fUpper);


	float factor = 0.2;
	do {
		factor += 0.1;
		returnPoints.clear();
		for (int i = 0; i < Vector300fUpper.rows(); i++)
		{
			std::vector<Point> obtainedPoints = VFormation::obtainPoints(factor, 10, i, Vector300fLower(i,0), Vector300fUpper(i,0));
			returnPoints.insert(std::end(returnPoints), std::begin(obtainedPoints), std::end(obtainedPoints));
			obtainedPoints.clear();
			
		}
	} while ((size/2 < returnPoints.size()));
	VFormation::mirrorPoints(returnPoints);
	return returnPoints;
}

std::vector<Point> VFormation::obtainPoints(float factor, int x, int y, float z_begin, float z_end) {
	std::vector<Point> obtainedPoints;

	int pointsCount = abs((z_begin - z_end) / factor);
	if (pointsCount == 0 && z_begin != z_end) {
		obtainedPoints.push_back(Point((z_begin + z_end) / 2, x,y));
		return obtainedPoints;
	}

	for (int i = 0; i < pointsCount; i++) {

		obtainedPoints.push_back(Point((z_begin + i * factor)-70, x-10, y-10));
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

void VFormation::mirrorPoints(std::vector<Point>& returnPoints) {
	for (auto point : returnPoints) {
		returnPoints.push_back(Point(-point.lat-1, point.alt, point.lngt));
	}
}