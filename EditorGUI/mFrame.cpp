#include "mFrame.h"
#include "../SwarmController/SettingsEditor.h"


wxBEGIN_EVENT_TABLE(mFrame, wxFrame)
	EVT_BUTTON(101, AddBtnOnButtonClicked)
	EVT_BUTTON(102, StartBtnOnButtonClicked)
wxEND_EVENT_TABLE()
using json = nlohmann::json;
using namespace std;

mFrame::mFrame() : wxFrame(nullptr, wxID_ANY, "Settings Editor",wxPoint(20,20),wxSize(800,1000)) {
	m_list_vehicles = new wxListBox(this, wxID_ANY, wxPoint(15, 30), wxSize(400, 800));
	m_add_btn = new wxButton(this, 101,"Add 100 Drone", wxPoint(370, 30), wxSize(200, 80));
	m_start_btn = new wxButton(this, 102, "Start Simulation", wxPoint(540, 860), wxSize(200, 80));
	std::ifstream i("C:/Users/dell/Documents/AirSim/settings.json");
	json settingsFile;
	i >> settingsFile;
	std::vector<std::string> dronesInFile;
	auto vehicles = settingsFile.find("Vehicles");
	for (json::iterator it = (*vehicles).begin(); it != (*vehicles).end(); ++it) {

		auto droneInfo = (*it).dump();
		

		m_list_vehicles->Append(it.key()+":"+droneInfo +'\n');


	}

}

mFrame::~mFrame() {

}
void mFrame::AddBtnOnButtonClicked(wxCommandEvent &evt) { 
	string jsonString = string();
	std::vector<std::string> droneList;
	jsonString += " { \"SettingsVersion\": 1.2,\"SimMode\": \"Multirotor\",\"Vehicles\" : {";
	for (int i = 0; i < 100; i++)
	{
		droneList.push_back("SwarmNode" + to_string(i + 1) + ", X : " + to_string((i % 10) * 2) + ", Y : " + to_string((i / 10) * 2) + ", Z : 5, Yaw : 90");
		jsonString += "\"SwarmNode" + to_string(i + 1) + "\": {\n\t\"VehicleType\": \"SimpleFlight\",\t\t\n\"X\" : " + to_string((i % 10) * 2) + ",\t\t\n\"Y\" : " + to_string((i / 10) * 2) + ",\t\t\n\"Z\" : 5,\t\t\n\"Yaw\" : 90}";
		if (i != 99) {
			jsonString += ",\n";
		}
	}
	jsonString += "}\n}";
	json j = json::parse(jsonString);
	std::ofstream o("C:/Users/dell/Documents/AirSim/settings.json");
	o << std::setw(4) << j << std::endl;

}

void mFrame::StartBtnOnButtonClicked(wxCommandEvent &evt) { //set path to unreal build and start with system()
	Close(); // close editor gui


	// path to unreal simulation executable
	// commented for working on other stuff
	// after finishing all necessary control codes, these lines will be uncommented
	
	wchar_t path1[] = L"\"C:\\Users\\dell\\Documents\\Unreal Projects\\Swarm\\Saved\\StagedBuilds\\WindowsNoEditor\\Swarm.exe\"";

	STARTUPINFOW process_startup_info2{ 0 };
	process_startup_info2.cb = sizeof(process_startup_info2); // setup size of strcture in bytes

	PROCESS_INFORMATION process_info2{ 0 };

	

	if (CreateProcessW(NULL, path1, NULL, NULL, TRUE, 0, NULL, NULL, &process_startup_info2, &process_info2)) // start unreal  simulation
	{
		CloseHandle(process_info2.hProcess);
		CloseHandle(process_info2.hThread);
	}

	wchar_t path2[] = L"\"E:\\Project Main\\SwarmController\\x64\\Debug\\SwarmController.exe\"";

	STARTUPINFOW process_startup_info1{ 0 };
	process_startup_info1.cb = sizeof(process_startup_info1); // setup size of strcture in bytes

	PROCESS_INFORMATION process_info1{ 0 };



	if (CreateProcessW(NULL, path2, NULL, NULL, TRUE, 0, NULL, NULL, &process_startup_info1, &process_info1)) // start unreal  simulation
	{
		CloseHandle(process_info1.hProcess);
		CloseHandle(process_info1.hThread);
	}
	

	 
	

	

	
}