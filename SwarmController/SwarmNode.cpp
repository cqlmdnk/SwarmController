#include "SwarmNode.h"
 





using namespace std;




float SwarmNode::getInfo()
{
	return 0.0f;
}

char* SwarmNode::getName() {
	return name;
}

SwarmNode::SwarmNode(char name[])//just id for now, other stuff will be added as needed
{
	SwarmNode::name = name;
}



SwarmNode::~SwarmNode()
{
}


