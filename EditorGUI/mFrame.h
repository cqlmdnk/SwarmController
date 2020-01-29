#pragma once
#include "wx/wx.h"
#include "../SwarmController/include/json.hpp"
#include "../SwarmController/Swarm.h"
#include <string>
#include <fstream> 
#include <iostream> 
#include<iomanip>
#include <windows.h>
#include <vector>



class mFrame : public wxFrame
{
public:
	mFrame();
	~mFrame();
public:
	wxListBox *m_list_vehicles = nullptr;
	wxButton *m_add_btn = nullptr;
	wxButton *m_start_btn = nullptr;
	std::vector<SwarmNode*> swarmVector;
	

	void AddBtnOnButtonClicked(wxCommandEvent &evt);
	void StartBtnOnButtonClicked(wxCommandEvent &evt);


	wxDECLARE_EVENT_TABLE();
};



