#include "mFrame.h"
#include "json.hpp"


wxBEGIN_EVENT_TABLE(mFrame, wxFrame)
	EVT_BUTTON(101, AddBtnOnButtonClicked)
	EVT_BUTTON(102, StartBtnOnButtonClicked)
wxEND_EVENT_TABLE()
using json = nlohmann::json;
using namespace std;

mFrame::mFrame() : wxFrame(nullptr, wxID_ANY, "Settings Editor",wxPoint(20,20),wxSize(800,1000)) {
	m_list_vehicles = new wxListBox(this, wxID_ANY, wxPoint(15, 30), wxSize(400, 800));
	m_add_btn = new wxButton(this, 101,"Add Drones", wxPoint(380, 30), wxSize(200, 80));
	m_start_btn = new wxButton(this, 102, "Start Simulation", wxPoint(540, 600), wxSize(200, 80));
	m_text_ctrl = new wxTextCtrl(this,103,"Enter number of drones",wxPoint(420, 110), wxSize(150, 30));

	loadListBox(m_list_vehicles);


}

mFrame::~mFrame() {

}
void mFrame::AddBtnOnButtonClicked(wxCommandEvent &evt) { 
	std::ifstream t("camera_settings.txt");
	std::string str((std::istreambuf_iterator<char>(t)),
		std::istreambuf_iterator<char>());
	string jsonString = string();
	std::vector<std::string> droneList;
	jsonString += " { \"SettingsVersion\": 1.2,\"SimMode\": \"Multirotor\", \"CaptureSettings\": [{\"ImageType\": 1,\"Width\" : 80,\"Height\" : 80}],\"Vehicles\" : {";
	int counter = atoi(m_text_ctrl->GetLineText(0));

	for (int i = 0; i < counter; i++)
	{
		droneList.push_back("SwarmNode" + to_string(i + 1) + ", X : " + to_string((i % 10) * 5) + ", Y : " + to_string((i / 10) * 5) + ", Z : 0, Yaw : 90");
		jsonString += "\"SwarmNode" + to_string(i + 1) + "\": {\n\t\"VehicleType\": \"SimpleFlight\",\t\t\n\"X\" : " 
			+ to_string((i % 10) * 4) + ",\t\t\n\"Y\" : " + to_string((i / 10) * 4) +
			",\t\t\n\"Z\" : 0,\t\t\n\"Yaw\" : 90,"+str+"}";
		if (i != counter-1) {
			jsonString += ",\n";
		}
	}
	jsonString += "}\n}";
	
	std::ofstream out("C:/Users/dell/Documents/AirSim/settings.json");
	out << jsonString;
	out.close();
	loadListBox(m_list_vehicles);

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


	// Entry point

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

void mFrame::loadListBox(wxListBox* m_list_vehicles) {
	m_list_vehicles->Clear();
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

		auto droneInfo = (*it).dump();


		m_list_vehicles->Append(it.key() + ":" + droneInfo + '\n');


	}
}