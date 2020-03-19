#include "ShapeFactory.h"
#include "Paraboloid.h"
#include "VFormation.h"
#include "Sphere.h"

std::shared_ptr<Points> ShapeFactory::CreateInstance(int type)
{

	Points * instance = nullptr;
	switch (type)
	{
	case PARAB:
		instance = new Paraboloid();
		break;
	case VFOR:
		instance = new VFormation();
		break;
	case SPHE:
		instance = new Sphere();
		break;
	}
	return std::shared_ptr<Points>(instance);
}
