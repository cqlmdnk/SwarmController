#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_SwarmGUI.h"

class SwarmGUI : public QMainWindow
{
	Q_OBJECT

public:
	SwarmGUI(QWidget *parent = Q_NULLPTR);
private slots:
	void hoverButtonPressed();
	void landButtonPressed();
	void takeoffButtonPressed();
	void moveButtonPressed();
	void loopSimulation();


private:
	Ui::SwarmGUIClass ui;
	QTimer* timer;
	
};
