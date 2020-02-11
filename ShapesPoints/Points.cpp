#include "Points.h"

Points::Points()
{

	// used points and resolution on calculations
	Vector300f.setLinSpaced(11, -30, 30);
	//mesh grid (& its transpose)
	Matrix300f = Vector300f.replicate(11, 1);

}
