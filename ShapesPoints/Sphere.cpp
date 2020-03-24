#include "Sphere.h"
Sphere::Sphere() : Points()
{

}

Sphere::~Sphere()
{

}

using namespace std;

const double PI = 3.141592654;
double irand(int min, int max);



// generate random number for the range (min, max)





std::vector<Vector3f> Sphere::getPoints(int size, int scale = 10)
{
	//operations will be done on Matrix300f and its transpose

	srand((unsigned)time(NULL));

	std::vector<Vector3f> returnPoints(size);

	double theta = 0, phi = 0;
	for (int i = 0; i < size; i++) {
		theta = 2 * PI *irand(0, 1);
		// corrrect
		phi = acos(2 * irand(0, 1) - 1.0);
		// incorrect
		//phi = PI*irand(0,1);
		returnPoints[i] = Vector3f(float(scale * cos(theta)*sin(phi)), float(scale * sin(theta)*sin(phi)), float((-1.0f) * scale * (cos(phi) + 1.0f) - 4.0f));

	}
	return returnPoints;
}


double irand(int min, int max)
{
	return ((double)rand() / ((double)RAND_MAX + 1.0)) * (max - min) + min;
}
