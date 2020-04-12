#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.hoverButton, SIGNAL(released()), this, SLOT(hoverButton()));
	ui.listWidget->addItem("asdasdasdsddddddddddddddddddd");
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(loopGL()));
	timer->start(100); // 100ms
	// Connect button signal to appropriate slot
	connect(ui.hoverButton, SIGNAL(released()), this, SLOT(hoverButtonPressed()));
}

void QtGuiApplication1::hoverButtonPressed() {
	ui.listWidget->addItem("Naber");
	ui.hoverButton->setText("Land");
}

void QtGuiApplication1::landButtonPressed()
{
}

void QtGuiApplication1::takeoffButtonPressed()
{
}

void QtGuiApplication1::moveButtonPressed()
{
}
void QtGuiApplication1::loopGL()
{
	//main update of openGL widget
	
}

