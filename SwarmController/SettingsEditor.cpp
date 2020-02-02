#include "SettingsEditor.h"
#include "include/json.hpp"


using json = nlohmann::json;





std::vector<std::string> SettingsEditor::readFile()
{
	std::ifstream i("C:/Users/dell/Documents/AirSim/settings.json");
	json settingsFile;
	i >> settingsFile;
	std::vector<std::string> dronesInFile;
	auto vehicles = settingsFile.find("Vehicles");
	for (json::iterator it = (*vehicles).begin(); it != (*vehicles).end(); ++it) {
		
		dronesInFile.push_back(it.key());
		std::cout << it.key()<< '\n';
		
	}
	return dronesInFile;
}




std::vector<SwarmNode*> SettingsEditor::getDronesFromFile() {
	std::vector<SwarmNode*> drones;
	std::vector<std::string> dronesInFile = SettingsEditor::readFile();

	for (string v : dronesInFile) {
		drones.push_back(new SwarmNode(v));
	}
	return drones;
}