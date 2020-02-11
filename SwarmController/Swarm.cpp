#include "Swarm.h"

static int size;


void Swarm::addNode(SwarmNode node)
{
}

void Swarm::go(std::vector<SwarmNode*> swarmVec)
{
	int c = 0;
	
	for (auto x : swarmVec) { // starting threads
		std::thread thread_ = std::thread(&SwarmNode::start, std::move(x), x->id);
		thread_.detach(); // detaching them , there is no need to wait for joining
		

	}
	
		// all threads will be started here
		
	
		
}
