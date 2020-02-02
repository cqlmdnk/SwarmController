#pragma once
#include <vector>
#include "Point.h"
#define PARAB 0
#define CIRC 1
#define SPHE 2
class Points
{
public:
	virtual std::vector<Point> getPoints() = 0;
};

