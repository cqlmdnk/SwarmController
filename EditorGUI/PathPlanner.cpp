#include "PathPlanner.h"
#include <wx/dcbuffer.h>
#include <thread>
#include "../Controller.h"


PathPlanner::PathPlanner() : wxFrame(nullptr, wxID_ANY, "Path Planner", wxPoint(0, 0), wxSize(1920, 1080))
{
	drawPane = new wxPanel(this);
	drawPane->Bind(wxEVT_LEFT_DOWN, &PathPlanner::mouseDown, this);
	wxClientDC dc(drawPane);
	std::thread thread_ = std::thread(&Controller::mainSim); // start sim
	thread_.detach();


}

PathPlanner::~PathPlanner()
{
}

void PathPlanner::paintEvent(wxPaintEvent & evt)
{
	evt.Skip();
	wxBufferedPaintDC dc(drawPane);
	render(dc);
}

void PathPlanner::mouseDown(wxMouseEvent & evt)
{
	evt.Skip();
	wxPoint pt = wxGetMousePosition();
	if (pt.x > -640 && pt.y > 720) {

	}
	else {
		drawPt = true;
		int mouseX = pt.x;
		int mouseY = pt.y;
		PointsVector::waypoints.emplace(Eigen::Vector3f((mouseX + 1280) / 10, (mouseY - 360) / 10, 0));
		//PointsVector::swarmCenter(0) = mouseX -640;
		//PointsVector::swarmCenter(1) = mouseY - 360;
		Refresh();
	}
	return;
}

wxBEGIN_EVENT_TABLE(PathPlanner, wxFrame)
EVT_PAINT(PathPlanner::paintEvent)
EVT_CLOSE(PathPlanner::onClose)

wxEND_EVENT_TABLE()


void PathPlanner::onClose(wxCloseEvent & evt) {
	evt.Skip();
	Destroy();

	exit(0);
}

void PathPlanner::onExit(wxCommandEvent& evt)
{
	evt.Skip();
	Destroy();
}


void PathPlanner::render(wxDC&  dc)
{
	// draw some text
	dc.Clear();
	dc.SetPen(wxPen(wxColor(0, 0, 255), 3));
	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_BDIAGONAL_HATCH));
	dc.DrawRectangle(wxRect(0, 0, 1280, 720));
	dc.SetPen(wxPen(wxColor(255, 0, 0), 2));
	dc.DrawLine(wxPoint(645, 0), wxPoint(645, 720));
	dc.DrawLine(wxPoint(0, 363), wxPoint(1280, 363));

	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_SOLID));

	dc.SetPen(wxPen(wxColor(205, 25, 53), 20)); // Second screen
	for (size_t i = 0; i < PointsVector::waypoints.size(); i++)
	{
		Eigen::Vector3f waypoint = PointsVector::waypoints.front();
		dc.DrawCircle(wxPoint((waypoint.x() * 10) + 640, (waypoint.y() * 10) + 180), 20);
		PointsVector::waypoints.emplace(waypoint);
		PointsVector::waypoints.pop();
	}
	//dc.DrawCircle(mouseX, mouseY-25, 20); //First screen




}