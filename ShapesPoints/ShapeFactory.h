#pragma once
#include <memory>
#include <string>
#include "Points.h"
class ShapeFactory
{
public:
	static std::shared_ptr<Points> CreateInstance(int type);
};

