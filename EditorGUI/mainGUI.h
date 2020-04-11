#pragma once
#include "wx/setup.h"
#include "mFrame.h"
#include "LidarVisualizer.h"
#include "PathPlanner.h"


class mainGUI : public wxApp
{
public:
	mainGUI();
	~mainGUI();
private:
	PathPlanner* m_frame1 = nullptr;

public:
	virtual bool OnInit();
	void onClose(wxCloseEvent & evt);

	wxDECLARE_EVENT_TABLE();
};

