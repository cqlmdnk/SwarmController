#pragma once
#include <string>
#include <fstream> 
#include <iostream> 
#include<iomanip>
#include "SwarmNode.h"

using namespace std;

 class SettingsEditor{
public:
	 // the function that will be called by Controller.cpp
	 // writes formed settings string to 'settings.json'
     std::vector<std::string> readFile(); // reads 'settings.json' from Documents/Airsim
	 std::vector<SwarmNode*> getDronesFromFile();
};
