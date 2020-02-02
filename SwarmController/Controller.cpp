#include "Controller.h"


using namespace std;
std::vector<float[3]> positions;

int main() { // entry point of the process that is executed by the end of Start Simulation button with unreal game
	cout << "Press Enter to start simulation" << endl; cin.get();

	SettingsEditor editor;
	
	Swarm swarm = Swarm();

	std::vector<SwarmNode*> swarmVector = editor.getDronesFromFile();
	
	
	swarm.go(swarmVector);

	Controller::controlMain(swarmVector);

	return 0;
}

 void Controller::controlMain(std::vector<SwarmNode*> swarmVector)
{
	 //go to here when shape is changed by user from gui
	ShapeFactory _factory = ShapeFactory();
	auto _shape = _factory.CreateInstance(PARAB);


	while (true) {
		
		std::vector<Point> _points = _shape->getPoints();
		dispatchPoints(_points);
		Sleep(5000);
	}
}
 void Controller::dispatchPoints(std::vector<Point> _points) {
	 //send points vector to shared area
 }
