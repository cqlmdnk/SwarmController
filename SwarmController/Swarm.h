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
	void addNode(SwarmNode node);
	void start(std::vector<SwarmNode*> swarmVec);
	int getId(string name);
	void go(std::vector<SwarmNode*> &swarmVec);
	void land(std::vector<SwarmNode*> &swarmVec);
	void hover(std::vector<SwarmNode*> &swarmVec);
	void takeoff(std::vector<SwarmNode*> &swarmVec);
	

	
};

