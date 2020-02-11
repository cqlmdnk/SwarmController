#pragma once
#include "Swarm.h"
#include "../ShapesPoints/Points.h"
#include "../ShapesPoints/ShapeFactory.h"
#include "SwarmNode.h"
#include "SettingsEditor.h"
#include <iostream>
#include <windows.h>
#include "../ShapesPoints/Point.h"
#include "PointsVector.h"
#include <conio.h>

class Controller{
public:
	
	static void controlMain(std::vector<SwarmNode*> swarmVector);
	static void dispatchPoints(std::vector<Point> _points);
};