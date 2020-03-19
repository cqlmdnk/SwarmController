#pragma once
#include <vector>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>  
#include "SwarmNode.h"
#include <Windows.h>
#include <iostream>
#include "PointsVector.h"
#include "Collision.h"


class Swarm {
public:
	static std::vector<PLocal> points;
	void addNode(SwarmNode node);
	void go(std::vector<SwarmNode*> swarmVec);
	int getId(string name);
	Vector3r getManeuver(bool* directions, Vector3r unitVec);
	
	

	
};

