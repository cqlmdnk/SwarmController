#include "SwarmNode.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>   




bool SwarmNode::flag() {
	return PointsVector::flagsOnThreads[SwarmNode::getId()];
}

using namespace std;
int SwarmNode::start(SwarmNode node)
{

	PointsVector::t_mtx.lock();

	PointsVector::client.enableApiControl(true, this->id);
	PointsVector::client.armDisarm(true, this->id);

	PointsVector::client.takeoffAsync(5, this->id);
	PointsVector::t_mtx.unlock();

	int id = getId();
	srand(id);
	int x, y, z;
		
		while (true) {
			
			
			std::unique_lock<std::mutex> lck(PointsVector::mtx[id]);
			PointsVector::cvr.wait(lck, [&] { return this->flag(); });
			PointsVector::t_mtx.lock();
			
			LandedState isLanded = PointsVector::client.getMultirotorState(this->id).landed_state;

			if (isLanded == LandedState::Landed) {
				PointsVector::client.enableApiControl(true, this->id);
				PointsVector::client.armDisarm(true, this->id);
				cout << "Landed, taking off..." << endl;
				PointsVector::client.takeoffAsync(3, this->id);
				
			}
			x = rand() % 100 - 50;
			y = rand() % 100 - 50;
			z = (rand() % 20) * -1;
			cout << "Moving to poistion..." + to_string(x)+ "-"+ to_string(y)+ "-"+ to_string(z) << endl;
			PointsVector::client.moveToPositionAsync(x, y, z, 4, Utils::max<float>(),
				DrivetrainType::MaxDegreeOfFreedom, YawMode(),
				-1, 1, this->id);
			
			PointsVector::t_mtx.unlock();
			PointsVector::flagsOnThreads[id] = false;
				
			PointsVector::cvr.notify_all();
			
		}
	
	

		return 0;
	
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



int SwarmNode::getId() {
	size_t last_index = this->id.find_last_not_of("0123456789");
	return std::stoi((this->id.substr(last_index + 1))) - 1;
}