#include "QtGuiApplication1.h"

QtGuiApplication1::QtGuiApplication1(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	ui.listWidget->addItem("asdasdasdsddddddddddddddddddd");
	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(loopGL()));
	timer->start(100); // 100ms
	// Connect button signal to appropriate slot
	connect(ui.hoverButton, SIGNAL(pressed()), this, SLOT(hoverButtonPressed()));
	connect(ui.moveButton, SIGNAL(pressed()), this, SLOT(moveButtonPressed()));
	std::thread _thread(&Controller::mainSim);
	_thread.detach();
}

void QtGuiApplication1::hoverButtonPressed() {
	ui.listWidget->addItem("Naber");
}

void QtGuiApplication1::landButtonPressed()
{
}

void QtGuiApplication1::takeoffButtonPressed()
{
}

void QtGuiApplication1::moveButtonPressed()
{
	auto rng = std::default_random_engine{};
	std::shuffle(std::begin(PointsVector::pointsOnThreads), std::end(PointsVector::pointsOnThreads), rng);
}
void QtGuiApplication1::loopSimulation()
{
	ui.widget->update();
	//main update of openGL widget
	
	
}

