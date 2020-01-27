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

};



