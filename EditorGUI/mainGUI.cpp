#include "mainGUI.h"

wxIMPLEMENT_APP(mainGUI);

mainGUI::mainGUI() {

}

mainGUI::~mainGUI() {

}
bool mainGUI::OnInit() {
	m_frame1 = new PathPlanner();
	m_frame1->Show();
	
	return true;
}

void mainGUI::onClose(wxCloseEvent & evt)
{

	
}
wxBEGIN_EVENT_TABLE(mainGUI, wxApp)
EVT_CLOSE(mainGUI::onClose)
wxEND_EVENT_TABLE()