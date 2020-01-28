#pragma once
#include "wx/wx.h"
#include "../SwarmController/include/json.hpp"
#include <string>
#include <fstream> 
#include <iostream> 
#include<iomanip>
#include <windows.h>


class mFrame : public wxFrame
{
public:
	mFrame();
	~mFrame();
public:
	wxListBox *m_list_vehicles = nullptr;
	wxButton *m_add_btn = nullptr;
	wxButton *m_start_btn = nullptr;

	void AddBtnOnButtonClicked(wxCommandEvent &evt);
	void StartBtnOnButtonClicked(wxCommandEvent &evt);


	wxDECLARE_EVENT_TABLE();
};



