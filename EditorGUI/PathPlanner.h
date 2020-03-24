#pragma once
#include "wx/wx.h"
#include <queue>


class PathPlanner : public wxFrame
{
public:
	PathPlanner();
	~PathPlanner();
	wxPanel *drawPane;
	wxButton *takeOffLandBtn = nullptr;
	wxButton *goBtn = nullptr;
	bool drawPt = false;
	void render(wxDC&  dc);
	void paintEvent(wxPaintEvent & evt);
	void mouseDown(wxMouseEvent & evt);
	void onExit(wxCommandEvent& event);
	void onClose(wxCloseEvent& event);
	void takeOffLandButton(wxCommandEvent& event);
	void goButton(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

};

