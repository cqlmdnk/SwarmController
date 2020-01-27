#include "mainGUI.h"

wxIMPLEMENT_APP(mainGUI);

mainGUI::mainGUI() {

}

mainGUI::~mainGUI() {

}
bool mainGUI::OnInit() {
	m_frame1 = new mFrame();
	m_frame1->Show();
	return true;
}