#pragma once
#include <string>
#include "vehicles/multirotor/api/MultirotorRpcLibClient.hpp"
#include <thread> 
#include <iostream>
#include <Windows.h>
#include "PointsVector.h"
class SwarmNode {
public:
	std::thread thread_;
	string id = "";
	int start(SwarmNode node);
	float move(float alt, float lat, float lon, float vel);
	float getInfo();
	int getId();
	bool flag();
public:
	SwarmNode(string id);
	~SwarmNode();
};
