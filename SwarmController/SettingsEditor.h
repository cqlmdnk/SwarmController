#pragma once
#include <string>

using namespace std;


int addDrones(int DroneCount); // the function that will be called by Controller.cpp
string createDroneString(); // for each drone that will be deployed
void writeFile(); // writes formed settings string to 'settings.json'
string readFile(); // reads 'settings.json' from Documents/Airsim