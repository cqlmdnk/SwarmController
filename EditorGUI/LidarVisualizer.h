#pragma once
#include "wx/wx.h"
#include "RenderTimer.h"
#include "deps/eigen3/Eigen/Eigen"
class LidarVisualizer : public wxFrame
{


public:
	LidarVisualizer();
	~LidarVisualizer();
	wxPanel *drawPane;

	void render(wxDC&  dc);
	int c = 5;
	float yaw=0;
	Eigen::Vector3f posVecs[16];
	RenderTimer* timer;
	void WxTimer1Timer(wxTimerEvent& event);
	void OnEraseBackGround(wxEraseEvent& event) {};
	void paintEvent(wxPaintEvent & evt);
	bool* getAvailDirs(std::string name);
	void OnClose(wxCloseEvent& evt) {};
	void OnKeyDownf(wxKeyEvent& evt);
	Eigen::Vector3f getManeVec(std::string name, Eigen::Vector3f unitTargetVec, float yaw);
	wxDECLARE_EVENT_TABLE();
};

