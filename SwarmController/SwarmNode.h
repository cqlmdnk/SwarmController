#pragma once
#include <string>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <thread> 
class SwarmNode {
public:
	std::thread thread_;
	string id = "";
	void start(SwarmNode node);
	float move(float alt, float lat, float lon, float vel);
	float getInfo();
public:
	SwarmNode(string id);
	~SwarmNode();
};
