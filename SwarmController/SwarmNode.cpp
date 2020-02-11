#include "SwarmNode.h"





bool SwarmNode::flag() {
	return PointsVector::flagsOnThreads[SwarmNode::getId()];
}

using namespace std;
int SwarmNode::start(SwarmNode node)
{

	msr::airlib::MultirotorRpcLibClient client;


	client.enableApiControl(true, this->id);
	client.armDisarm(true, this->id);

	client.takeoffAsync(1, this->id)->waitOnLastTask();

	client.hoverAsync(this->id);

	int id = getId();
	
		
		
		while (true) {
			

			std::unique_lock<std::mutex> lck(PointsVector::mtx[id]);
			PointsVector::cvr.wait(lck, [&] { return this->flag(); });
			
				client.enableApiControl(true, this->id);
				client.armDisarm(true, this->id);

				cout << this->id+":  "+to_string((PointsVector::pointsOnThreads.at(id).lngt) * 3) + " " + to_string((PointsVector::pointsOnThreads.at(id).lat) / 10) + " " + to_string((PointsVector::pointsOnThreads.at(id).alt) * 3 * (-1)) << endl;;
				client.moveToPositionAsync((PointsVector::pointsOnThreads.at(id).lngt)*3, (PointsVector::pointsOnThreads.at(id).lat)/20, (PointsVector::pointsOnThreads.at(id).alt)*3 * (-1), 2, Utils::max<float>(),
					DrivetrainType::MaxDegreeOfFreedom, YawMode(),
					-1, 1, this->id)->waitOnLastTask();
				
				client.hoverAsync(this->id);
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