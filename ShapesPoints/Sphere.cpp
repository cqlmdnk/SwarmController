#include "Sphere.h"
Sphere::Sphere() : Points()
{

}

Sphere::~Sphere()
{

}



std::vector<Point> Sphere::getPoints(int size)
{
	//operations will be done on Matrix300f and its transpose

	std::vector<Point> returnPoints;

	MatrixXf Matrix300fUpper = MatrixXf(11, 11);
	MatrixXf Matrix300fLower = MatrixXf(11, 11);

	// sphere formulas

	
	

	Points::normalizeMatrices(Matrix300fUpper, Matrix300fLower);
	

	float factor = 0.2;
	do {
		factor += 0.10;
		returnPoints.clear();
		
	} while ((size + 5 < returnPoints.size()));
	return returnPoints;
}


