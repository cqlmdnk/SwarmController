#pragma once

#include <QtWidgets/QMainWindow>
#include <QTimer>
#include "ui_QtGuiApplication1.h"

class QtGuiApplication1 : public QMainWindow
{
	Q_OBJECT

public:
	QtGuiApplication1(QWidget *parent = Q_NULLPTR);
private slots:
	void hoverButtonPressed();
	void landButtonPressed();
	void takeoffButtonPressed();
	void moveButtonPressed();
	void loopGL();


private:
	Ui::QtGuiApplication1Class ui;
	QTimer* timer;
	
};
