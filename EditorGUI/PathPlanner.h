#pragma once
#include "wx/wx.h"
#include <queue>

class PathPlanner : public wxFrame
{
public:
	PathPlanner();
	~PathPlanner();
	wxPanel *drawPane;
	bool drawPt = false;
	void render(wxDC&  dc);
	void paintEvent(wxPaintEvent & evt);
	void mouseDown(wxMouseEvent & evt);
	void onClose(wxCloseEvent & evt);
	void onExit(wxCommandEvent& event);
	wxDECLARE_EVENT_TABLE();

};

