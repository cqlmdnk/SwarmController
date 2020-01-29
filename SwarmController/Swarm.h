#pragma once
#include <vector>
#include "SwarmNode.h"


class Swarm {
public:
	void addNode(SwarmNode node);
	void go(std::vector<SwarmNode*> swarmVec);
};

