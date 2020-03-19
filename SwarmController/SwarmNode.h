#pragma once
#include <string>

enum Direction {
	FRONT,
	BACK,
	LEFT,
	RIGHT,
	TOP,
	BOTTOM
};
class SwarmNode {
public:
	
	float getInfo();
	char* getName();
	SwarmNode(char name[]);
	~SwarmNode();
private:
	char* name;
};
