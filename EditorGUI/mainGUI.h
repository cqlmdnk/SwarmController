#pragma once
#include "wx/wx.h"
#include "mFrame.h"


class mainGUI : public wxApp
{
public:
	mainGUI();
	~mainGUI();
private:
	mFrame* m_frame1 = nullptr;

public:
	virtual bool OnInit();


};

