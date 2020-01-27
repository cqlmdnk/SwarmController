#include "mFrame.h"

mFrame::mFrame() : wxFrame(nullptr, wxID_ANY, "Settings Editor",wxPoint(20,20),wxSize(800,1000)) {
	m_list_vehicles = new wxListBox(this, wxID_ANY, wxPoint(15, 30), wxSize(400, 800));
	m_add_btn = new wxButton(this, wxID_ANY,"Add Vehicle", wxPoint(350, 30), wxSize(200, 20));
}

mFrame::~mFrame() {

}