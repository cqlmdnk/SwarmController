#pragma once

class SwarmNode {
public:
	float move(float alt, float lat, float lon, float vel);
	float getInfo();
public:
	SwarmNode();
	~SwarmNode();
};
