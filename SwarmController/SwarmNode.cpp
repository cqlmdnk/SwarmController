#include "SwarmNode.h"


using namespace std;
void SwarmNode::start(SwarmNode node)
{
	
	msr::airlib::MultirotorRpcLibClient client;

	
	client.enableApiControl(true, this->id);
	client.armDisarm(true, this->id);
	client.takeoffAsync(1 , this->id)->waitOnLastTask();

	
		
	while (true) {
		auto position = client.getMultirotorState(this->id).getPosition(); // from current location
		client.moveToPositionAsync(position.x() + 5, position.y(), position.z(), 1, Utils::max<float>(),
			DrivetrainType::MaxDegreeOfFreedom, YawMode(),
			-1, 1, this->id)->waitOnLastTask();

		Sleep(3000);
		}
		

		

	
	client.landAsync(60, this->id)->waitOnLastTask();



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
