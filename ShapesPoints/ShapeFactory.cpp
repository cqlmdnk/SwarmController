#include "ShapeFactory.h"
#include "Paraboloid.h"

std::shared_ptr<Points> ShapeFactory::CreateInstance(int type)
{

	Points * instance = nullptr;
	switch (type)
	{
	case PARAB:
		instance = new Paraboloid();
		break;
	}
	return std::shared_ptr<Points>(instance);
}
