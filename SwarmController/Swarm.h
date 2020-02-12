#pragma once
#include <vector>
#include "SwarmNode.h"


class Swarm {
public:
	static std::vector<Point> points;
	void addNode(SwarmNode node);
	void go(std::vector<SwarmNode*> swarmVec);
	
	
	
	

	
};

