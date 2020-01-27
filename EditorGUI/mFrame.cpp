#include "mFrame.h"

wxBEGIN_EVENT_TABLE(mFrame, wxFrame)
	EVT_BUTTON(101, OnButtonClicked)
wxEND_EVENT_TABLE()


mFrame::mFrame() : wxFrame(nullptr, wxID_ANY, "Settings Editor",wxPoint(20,20),wxSize(800,1000)) {
	m_list_vehicles = new wxListBox(this, wxID_ANY, wxPoint(15, 30), wxSize(400, 800));
	m_add_btn = new wxButton(this, 101,"Add Vehicle", wxPoint(370, 30), wxSize(200, 80));
	m_rem_btn = new wxButton(this, 102, "Remove Vehicle", wxPoint(370, 110), wxSize(200, 80));
	m_addMShip_btn = new wxButton(this, 103, "Add Mothership", wxPoint(370, 190), wxSize(200, 80));


}

mFrame::~mFrame() {

}
void mFrame::OnButtonClicked(wxCommandEvent &evt) { 

	

}