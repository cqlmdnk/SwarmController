#include "PathPlanner.h"
#include <wx/dcbuffer.h>
#include <thread>
#include "../Controller.h"


PathPlanner::PathPlanner() : wxFrame(nullptr, wxID_ANY, "Path Planner", wxPoint(0, 0), wxSize(1920, 1080))
{
	drawPane = new wxPanel(this);
	takeOffLandBtn =  new wxButton(drawPane, 101, "Take off", wxPoint(1300, 200), wxSize(100, 20));
	goBtn = new wxButton(drawPane, 102, "Go", wxPoint(1300, 320), wxSize(100, 20));
	goBtn->Enable(true);
	takeOffLandBtn->Enable(true);
	wxBoxSizer *vbox = new wxBoxSizer(wxHORIZONTAL);
	drawPane->SetSizer(vbox);

	drawPane->Bind(wxEVT_LEFT_DOWN, &PathPlanner::mouseDown, this);
	
	
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
	wxPoint screenpt = wxGetMousePosition();
	wxPoint pt = this->ScreenToClient(screenpt);
	if (pt.x > 0 && pt.x < 1280 && pt.y < 720) {
		drawPt = true;
		int mouseX = pt.x;
		int mouseY = pt.y;
		PointsVector::waypoints.emplace(Eigen::Vector3f((mouseX -640), (mouseY - 360), 0));
		//PointsVector::swarmCenter(0) = mouseX -640;
		//PointsVector::swarmCenter(1) = mouseY - 360;
		Refresh();
	}
	else {
		
	}
	return;
}

wxBEGIN_EVENT_TABLE(PathPlanner, wxFrame)
EVT_PAINT(PathPlanner::paintEvent)
EVT_CLOSE(PathPlanner::onClose)
EVT_BUTTON(101, PathPlanner::takeOffLandButton)
EVT_BUTTON(102, PathPlanner::goButton)

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

void PathPlanner::takeOffLandButton(wxCommandEvent & event)
{
	if (PointsVector::state != LAND) {
		PointsVector::state = LAND;
		takeOffLandBtn->SetLabelText("Take off");
	}
	else {
		PointsVector::state = TAKEOFF;
		takeOffLandBtn->SetLabelText("Land");
	}
	

}

void PathPlanner::goButton(wxCommandEvent & event)
{
	if (PointsVector::state != GO) {
		PointsVector::state = GO;
		goBtn->SetLabelText("Hover");
	}
	else {
		PointsVector::state = HOVER;
		goBtn->SetLabelText("Go");
	}

}


void PathPlanner::render(wxDC&  dc)
{
	// draw some text

	dc.Clear();
	dc.DrawText(wxString(std::to_string(PointsVector::totalDistance)), 1300, 100);
	
	dc.SetPen(wxPen(wxColor(0, 0, 255), 3));
	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_BDIAGONAL_HATCH));
	dc.DrawRectangle(wxRect(0, 0, 1280, 720));
	dc.SetPen(wxPen(wxColor(255, 0, 0), 2));
	dc.DrawLine(wxPoint(645, 0), wxPoint(645, 720));
	dc.DrawLine(wxPoint(0, 363), wxPoint(1280, 363));

	dc.SetBrush(wxBrush(wxColor(0, 0, 0), wxBRUSHSTYLE_SOLID));

	// Second screen
	
	dc.SetPen(wxPen(wxColor(0, 40, 255), 2));
	if (PointsVector::waypoints.size() > 0) {
		Eigen::Vector3f waypoint = PointsVector::waypoints.front();
		dc.DrawLine(wxPoint(PointsVector::nodePositions.at(0).x() + 640, PointsVector::nodePositions.at(0).y() + 360), wxPoint((PointsVector::waypoints.front().x()) + 640, (PointsVector::waypoints.front().y()) + 360));

	}

	for (size_t i = 0; i < PointsVector::waypoints.size(); i++)
	{
		dc.SetPen(wxPen(wxColor(205, 25, 53), 20));
		Eigen::Vector3f waypoint = PointsVector::waypoints.front();
		dc.DrawCircle(wxPoint((waypoint.x()) + 640, (waypoint.y()) + 360), 20);
		PointsVector::waypoints.emplace(waypoint);
		PointsVector::waypoints.pop();
		if (i < PointsVector::waypoints.size() - 1) {
			dc.SetPen(wxPen(wxColor(0, 50, 255), 2));
			dc.DrawLine(wxPoint((waypoint.x()) + 640, (waypoint.y()) + 360), wxPoint((PointsVector::waypoints.front().x()) + 640, (PointsVector::waypoints.front().y()) + 360));

		}
	}
	dc.SetPen(wxPen(wxColor(0, 40, 255), 2));
	for (Vector3f vec : PointsVector::nodePositions) {
		dc.DrawCircle(wxPoint((vec.x()) + 640, (vec.y()) + 360), 2);
	}
	
	//dc.DrawCircle(mouseX, mouseY-25, 20); //First screen




}