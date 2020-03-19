#include "SettingsEditor.h"
#include "include/json.hpp"


using json = nlohmann::json;





std::vector<std::string> SettingsEditor::readFile()
{
	
	
	std::ifstream t("C:/Users/dell/Documents/AirSim/settings.json");
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());



	auto settingsFile = json::parse(str);

	std::vector<std::string> dronesInFile;
	auto vehicles = settingsFile.find("Vehicles");
	
	for (json::iterator it = (*vehicles).begin(); it != (*vehicles).end(); ++it) {
		
		dronesInFile.push_back(it.key());
		
	}
	return dronesInFile;
}




std::vector<SwarmNode*> SettingsEditor::getDronesFromFile() {
	std::vector<SwarmNode*> drones;
	std::vector<std::string> dronesInFile = SettingsEditor::readFile();
	

	for (string name : dronesInFile) {
		char* cstr = new char[name.size() + 1];

		std::copy(name.begin(), name.end(), cstr);
		cstr[name.size()] = '\0';

		drones.push_back(new SwarmNode(cstr));
		
	}
	return drones;
}