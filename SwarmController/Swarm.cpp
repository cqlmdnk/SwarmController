#include "Swarm.h"

class Swarm {
	static int size;

public :static std::vector<SwarmNode> swarmVec;


	


	static void addNode(SwarmNode node) {
		swarmVec.push_back(node);
		size++;
	}


	
};


