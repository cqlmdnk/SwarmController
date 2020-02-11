#include "Controller.h"
#define SIZE 100

using namespace std;

int main() { // entry point of the process that is executed by the end of Start Simulation button with unreal game
	cout << "Press Enter to start simulation" << endl; cin.get();

	SettingsEditor editor;
	
	Swarm swarm = Swarm();

	std::vector<SwarmNode*> swarmVector = editor.getDronesFromFile();
	

	Sleep(1000);
	swarm.go(swarmVector);

	Controller::controlMain(swarmVector);
	while (1) {
		int chr = getch();
		if (chr == 72) {
			Controller::controlMain(swarmVector);
		}
		else if (chr == 80) {
			Controller::controlMain(swarmVector);
		}

	}
	return 0;
}

 void Controller::controlMain(std::vector<SwarmNode*> swarmVector)
{
	 //go to here when shape is changed by user from gui
	ShapeFactory _factory = ShapeFactory();
	auto _shape = _factory.CreateInstance(PARAB);


	
		
	std::vector<Point> _points = _shape->getPoints(SIZE);
	std::cout << _points.size() << std::endl;
	
	dispatchPoints(_points);
		
		

}
 void Controller::dispatchPoints(std::vector<Point> _points) {
	 
	 
	 
	 for (int i = 0; i < 100; i++) {
		 std::unique_lock<std::mutex> lck(PointsVector::mtx[i]);
		 PointsVector::flagsOnThreads[i] = true;
	}
	 PointsVector::pointsOnThreads.clear();
	 PointsVector::pointsOnThreads.insert(end(PointsVector::pointsOnThreads), begin(_points), end(_points));
	 PointsVector::cvr.notify_all();

 }
