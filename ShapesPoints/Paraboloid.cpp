#include "Paraboloid.h"

using namespace Eigen;

Paraboloid::Paraboloid() : Points()
{
	
}

Paraboloid::~Paraboloid()
{

}


std::vector<Point> Paraboloid::getPoints(int size)
{
	//operations will be done on Matrix300f and its transpose
	
	std::vector<Point> returnPoints;
	
	MatrixXf Matrix300fUpper = MatrixXf(11, 11);
	MatrixXf Matrix300fLower = MatrixXf(11, 11);

	// paraboloid formulas
	Matrix300fLower = ((((Matrix300f.array().pow(2) / pow(0.2, 2)) + (Matrix300f.transpose().array().pow(2) / (pow(0.2, 2)))))*0.4) - 600.0;
	Matrix300fUpper = (((Matrix300f.array().pow(2) / pow(1.2, 2)) + (Matrix300f.transpose().array().pow(2) / (pow(1.2, 2)))) *10.0) ;

	Points::normalizeMatrices(Matrix300fLower, Matrix300fUpper);

	float factor = 0.2;
	do{
		factor += 0.10;
		returnPoints.clear();
		for (int i = 0; i < Matrix300fLower.rows(); i++)
		{
			for (int j = 0; j < Matrix300fLower.cols(); j++)
			{
				std::vector<Point> obtainedPoints = Paraboloid::obtainPoints(factor, i, j, Matrix300fLower(i, j), Matrix300fUpper(i, j));
				returnPoints.insert(std::end(returnPoints), std::begin(obtainedPoints), std::end(obtainedPoints)); 
				obtainedPoints.clear();
			}
		}
	} while ((size+5 < returnPoints.size()));
	return returnPoints;
}

std::vector<Point> Paraboloid::obtainPoints(float factor, int x, int y, float z_begin, float z_end) {
	std::vector<Point> obtainedPoints;

	int pointsCount = abs((z_begin - z_end) / factor);
	if (pointsCount == 0 && z_begin != z_end) {
		obtainedPoints.push_back(Point((z_begin + z_end) / 2, x, y));
		return obtainedPoints;
	}

	for (int i = 0; i < pointsCount; i++) {

		obtainedPoints.push_back(Point(z_begin + i * factor, x, y));
	}
	return obtainedPoints;

}


