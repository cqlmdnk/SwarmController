#include "Points.h"
#include <iostream>
#include <math.h>
Points::Points()
{

	// used points and resolution on calculations
	Vector300f.setLinSpaced(11, -30, 30);
	//mesh grid (& its transpose)
	Matrix300f = Vector300f.replicate(11, 1);

}




double Points::floorUnry(double x) {
	return std::floor(x);
}

void Points::normalizeMatrices(MatrixXf& lower, MatrixXf& upper)
{
	
	upper = (upper.array() > lower.array()).select(upper, 0);
	lower = (lower.array() < upper.array()).select(lower, 0);
	double upperMin = upper.minCoeff();
	double lowerMin = lower.minCoeff();


	if (upperMin < lowerMin) {
		lower = (lower.array() - upperMin).matrix();
		upper = (upper.array() - upperMin).matrix();
	}
	else {
		lower = (lower.array() - lowerMin).matrix();
		upper = (upper.array() - lowerMin).matrix();
	}
	double nupperMin = upper.minCoeff();
	double nlowerMin = lower.minCoeff();
	if (nupperMin < nlowerMin) {
		lower = (lower.array() / nlowerMin).matrix();
		upper = (upper.array() / nlowerMin).matrix();
	}
	else {
		lower = (lower.array() / nupperMin).matrix();
		upper = (upper.array() / nupperMin).matrix();
	}

	lower = (lower.array() * 10).matrix();
	upper = (upper.array() * 10).matrix();






}
