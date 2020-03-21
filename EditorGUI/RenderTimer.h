#pragma once
#include "wx/wx.h"
class RenderTimer: wxTimer{
	wxPanel* pane;
public:
	RenderTimer(wxPanel* pane);
	void Notify();
	void start();
	
};

