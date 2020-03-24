#include "Paraboloid.h"

using namespace Eigen;

Paraboloid::Paraboloid() : Points()
{

}

Paraboloid::~Paraboloid()
{

}


std::vector<Vector3f> Paraboloid::getPoints(int size, int scale = 10)
{
	//operations will be done on Matrix300f and its transpose

	std::vector<Vector3f> returnPoints;

	MatrixXf Matrix300fUpper = MatrixXf(int(size / 15 + 1), int(size / 15 + 1));
	MatrixXf Matrix300fLower = MatrixXf(int(size / 15 + 1), int(size / 15 + 1));

	// paraboloid formulas
	Matrix300fLower = ((((Matrix300f.array().pow(2) / pow(0.2, 2)) + (Matrix300f.transpose().array().pow(2) / (pow(0.2, 2)))))*0.4) - 600.0;
	Matrix300fUpper = (((Matrix300f.array().pow(2) / pow(1.2, 2)) + (Matrix300f.transpose().array().pow(2) / (pow(1.2, 2)))) *10.0);

	Points::normalizeMatrices(Matrix300fLower, Matrix300fUpper);

	float factor = 0.1f;
	do {
		factor += 0.01f;
		returnPoints.clear();
		for (int i = 0; i < Matrix300fLower.rows(); i++)
		{
			for (int j = 0; j < Matrix300fLower.cols(); j++)
			{
				std::vector<Vector3f> obtainedPoints = Paraboloid::obtainPoints(factor, i, j, Matrix300fLower(i, j), Matrix300fUpper(i, j));
				returnPoints.insert(std::end(returnPoints), std::begin(obtainedPoints), std::end(obtainedPoints));
				obtainedPoints.clear();
			}
		}
		std::cout << returnPoints.size() << std::endl;
	} while ((size + 1 < returnPoints.size()));
	return returnPoints;
}

std::vector<Vector3f> Paraboloid::obtainPoints(float factor, int x, int y, float z_begin, float z_end) {
	std::vector<Vector3f> obtainedPoints;

	int pointsCount = int(abs((z_begin - z_end) / factor));
	if (pointsCount == 0 && z_begin != z_end) {
		obtainedPoints.push_back(Vector3f(float((z_begin + z_end) / 4), float(x), float(-(y + 10)*0.8f)));
		return obtainedPoints;
	}

	for (int i = 0; i < pointsCount; i++) {

		obtainedPoints.push_back(Vector3f(float((z_begin + i * factor)/2.0f), float(x), float(-(y + 10.0f)*0.8f)));
	}
	return obtainedPoints;

}


