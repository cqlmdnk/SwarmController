#include "Controller.h"
#define SIZE 50

using namespace std;
enum SIGNAL {DEC_Z, INC_Z, DEC_Y, INC_Y, DEC_X, INC_X, NOP};

int main() { // entry point of the process that is executed by the end of Start Simulation button with unreal game
	cout << "Press Enter to start simulation" << endl; cin.get();
	
	SettingsEditor editor;
	



	
	Swarm swarm = Swarm();

	std::vector<SwarmNode*> swarmVector = editor.getDronesFromFile();
	


	Sleep(1000);
	

	ShapeFactory _factory = ShapeFactory();
	auto _shape = _factory.CreateInstance(SPHE);

	std::vector<Vector3f> _points = _shape->getPoints(SIZE,5);

	Controller::dispatchPoints(_points);
	std::thread thread_ = std::thread(&Swarm::go, std::move(swarm), swarmVector);
	thread_.detach(); // detaching thread , there will be no join
	
	Sleep(2000);
	

	while (1) {
		//Controller::dispatchPoints(_points);
		Sleep(2000);
		

	}
	return 0;
}


 void Controller::dispatchPoints(std::vector<Vector3f> _points) {
	 
	 
	

	 PointsVector::pointsOnThreads.insert(end(PointsVector::pointsOnThreads), begin(_points), end(_points));
	

 }

