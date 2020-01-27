#pragma once
#include "wx/wx.h"
class mFrame : public wxFrame
{
public:
	mFrame();
	~mFrame();
public:
	wxListBox *m_list_vehicles = nullptr;
	wxButton *m_add_btn = nullptr;
	wxButton *m_rem_btn = nullptr;
	wxButton *m_addMShip_btn = nullptr;

	void OnButtonClicked(wxCommandEvent &evt);
	

	wxDECLARE_EVENT_TABLE();
};



