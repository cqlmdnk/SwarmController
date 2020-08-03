#include "SwarmGUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	SwarmGUI w;
	
	w.show();
	return a.exec();
}
