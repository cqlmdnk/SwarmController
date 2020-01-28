#include "mFrame.h"
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


}

mFrame::~mFrame() {

}
void mFrame::AddBtnOnButtonClicked(wxCommandEvent &evt) { 
	string jsonString = string();
	jsonString += " { \"SettingsVersion\": 1.2,\"SimMode\": \"Multirotor\",\"Vehicles\" : {";
	for (int i = 0; i < 100; i++)
	{
		m_list_vehicles->AppendString("SwarmNode" + to_string(i + 1)+ ", X : " + to_string((i % 10) * 2) + ", Y : " + to_string((i / 10) * 2) + ", Z : 5, Yaw : 90");
		jsonString += "\"SwarmNode"+to_string(i+1)+"\": {\n\t\"VehicleType\": \"SimpleFlight\",\t\t\n\"X\" : " + to_string((i%10)*2) + ",\t\t\n\"Y\" : " + to_string((i/10)*2) + ",\t\t\n\"Z\" : 5,\t\t\n\"Yaw\" : 90}";
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
	string path = "\"C:\\Users\\dell\\Documents\\Unreal Projects\\Swarm\\Saved\\StagedBuilds\\WindowsNoEditor\\Swarm.exe\"";
	int result = system(path.c_str());



	//start controller
	//call controller main function
}