#include "SwarmNode.h"
#include <iostream>


void SwarmNode::start(SwarmNode node)
{
	int v = 0;
	while (true) {
		v++;
		std::cout << "pause of " << v << " seconds ended\n";
		if (v > 1000)
			v = 0;
	}
}


float SwarmNode::move(float alt, float lat, float lon, float vel)
{
	return 0.0f;
}

float SwarmNode::getInfo()
{
	return 0.0f;
}

SwarmNode::SwarmNode(string id)//just id for now, other stuff will be added as needed
{
	this->id = id;
}



SwarmNode::~SwarmNode()
{
}
