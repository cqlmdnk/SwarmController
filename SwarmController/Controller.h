#pragma once
#include "Swarm.h"
#include "../ShapesPoints/Points.h"
#include "../ShapesPoints/ShapeFactory.h"
#include "SwarmNode.h"
#include "SettingsEditor.h"
#include <iostream>
#include <windows.h>
#include "../ShapesPoints/PLocal.h"
#include "PointsVector.h"
#include <conio.h>

class Controller{
public:
	
	static void dispatchPoints(std::vector<Vector3f> _points);
};