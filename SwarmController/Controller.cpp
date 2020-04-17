#include "Controller.h"
#define SIZE 40

using namespace std;
enum SIGNAL {DEC_Z, INC_Z, DEC_Y, INC_Y, DEC_X, INC_X, NOP};
int getId(string name);
void Controller::mainSim() { // entry point of the process that is executed by the end of Start Simulation button with unreal game
	cout << "Press Enter to start simulation" << endl; cin.get();
	
	SettingsEditor editor;
	
	Swarm swarm = Swarm();
	std::vector<SwarmNode*> swarmVector = editor.getDronesFromFile();

	Sleep(1000);
	for (size_t i = 0; i < SIZE; i++)
	{
		PointsVector::nodePositions.emplace_back(Vector3f(0, 0, 0));
	}
	
	ShapeFactory _factory = ShapeFactory();
	auto _shape = _factory.CreateInstance(SPHE);

	std::vector<Vector3f> _points = _shape->getPoints(SIZE,10);

	Controller::dispatchPoints(_points);
	
	
	bool reach = true;
	
	swarm.start(swarmVector);
	swarm.takeoff(swarmVector);
	Sleep(3000);
	while (1) {
		//Controller::dispatchPoints(_points);
		for (auto node : swarmVector) {
			Vector3f pos = PointsVector::client.getMultirotorState(node->getName()).getPosition();
			PointsVector::nodePositions.at(getId(node->getName())) = pos;
		}
		swarm.go(swarmVector);
		Sleep(500);
		/*	
		switch (PointsVector::state)
		{
		case GO:
			swarm.go(swarmVector);
			break;
		case LAND:
			swarm.land(swarmVector);
			break;
		case HOVER:
			swarm.hover(swarmVector);
			break;
		case TAKEOFF:
			swarm.takeoff(swarmVector);
			Sleep(3000);
			PointsVector::state = HOVER;
			break;
		default:
			break;
		}
		Sleep(300);
		if (PointsVector::waypoints.size() > 0 && reach && PointsVector::state == GO) {
			
			Eigen::Vector3f waypoint = PointsVector::waypoints.front();
			
			PointsVector::swarmCenter(0) = waypoint.x();
			PointsVector::swarmCenter(1) = waypoint.y();
			reach = false;
			Sleep(500);
		}
		if (PointsVector::totalDistance < 50 && PointsVector::state ==GO) {

			PointsVector::waypoints.pop();
			reach = true;
		}
		*/

	}
	
}


 void Controller::dispatchPoints(std::vector<Vector3f> _points) {
	 
	 
	 

	 PointsVector::pointsOnThreads.insert(end(PointsVector::pointsOnThreads), begin(_points), end(_points));
	

 }

 int getId(string name) {
	 size_t last_index = name.find_last_not_of("0123456789");
	 return std::stoi((name.substr(last_index + 1))) - 1;
 }