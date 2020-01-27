#include "SettingsEditor.h"
#include "include/json.hpp"
#include <fstream> 
#include <iostream> 

using json = nlohmann::json;

int addDrones(int DroneCount) 
{
	return 0;
}

string createDroneString()
{
	return string();
}

void writeFile()
{
}

string readFile()
{
	std::ifstream i("C:/Users/dell/Documents/AirSim/settings.json");
	json settingsFile;
	i >> settingsFile;

	auto vehicles = settingsFile.find("Vehicles");
	for (json::iterator it = (*vehicles).begin(); it != (*vehicles).end(); ++it) {
		
		
		std::cout << it.key()<< '\n';
		std::cout << *it << '\n';
		
	}
	return string();
}
