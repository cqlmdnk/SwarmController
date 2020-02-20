#include "Controller.h"
#define SIZE 100

using namespace std;
enum SIGNAL {DEC_Z, INC_Z, DEC_Y, INC_Y, DEC_X, INC_X, NOP};

int main() { // entry point of the process that is executed by the end of Start Simulation button with unreal game
	cout << "Press Enter to start simulation" << endl; cin.get();

	SettingsEditor editor;
	
	Swarm swarm = Swarm();

	std::vector<SwarmNode*> swarmVector = editor.getDronesFromFile();
	

	Sleep(1000);
	swarm.go(swarmVector);

	ShapeFactory _factory = ShapeFactory();
	auto _shape = _factory.CreateInstance(VFOR);

	std::vector<Point> _points = _shape->getPoints(100);
	std::cout << _points.size() << std::endl;
	int chr = getch();

	Controller::dispatchPoints(_points);
	Sleep(2000);
	Controller::dispatchPoints(_points);

	while (1) {
		for (int i = 0; i < 100; i++) {
			std::unique_lock<std::mutex> lck(PointsVector::mtx[i]);
			PointsVector::flagsOnThreads[i] = true;
		}

		PointsVector::cvr.notify_all();
		PointsVector::cvr.notify_one();
		Sleep(10*1000);
		/*
		if (chr == 72) {
			Controller::tunePositions(INC_Z);
		}
		else if (chr == 80) {
			Controller::tunePositions(DEC_Z);
		}
		else if (chr == 49) {
			Controller::tunePositions(INC_Y);
		}
		else if (chr == 50) {
			Controller::tunePositions(DEC_Y);
		}
		else if (chr == 51) {
			Controller::tunePositions(INC_X);
		}
		else if (chr == 52) {
			Controller::tunePositions(DEC_X);
		}
		else if (chr == 10) {
			Controller::dispatchPoints(_points);
		}
		else {*/

				
			//}
		

	}
	return 0;
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
 void Controller::tunePositions(int signal) {
	 for (int i = 0; i < 100; i++) {
		 std::unique_lock<std::mutex> lck(PointsVector::mtx[i]);
		 PointsVector::flagsOnThreads[i] = true;
	 }
	 switch (signal) {
	 case INC_Z:
		 for (int i = 0; i < SIZE;i++) {
			 PointsVector::pointsOnThreads.at(i).lat *= 2;
		 }
		 break;
	 case DEC_Z:
		 for (int i = 0; i < SIZE; i++) {
			 PointsVector::pointsOnThreads.at(i).lat /= 2;
		 }
		 break;
	 case INC_Y:
		 for (int i = 0; i < SIZE; i++) {
			 PointsVector::pointsOnThreads.at(i).alt *= 2;
		 }
		 break;
	 case DEC_Y:
		 for (int i = 0; i < SIZE; i++) {
			 PointsVector::pointsOnThreads.at(i).alt /= 2;
		 }
		 break;
	 case INC_X:
		 for (int i = 0; i < SIZE; i++) {
			 PointsVector::pointsOnThreads.at(i).lngt *= 2;
		 }
		 break;
	 case DEC_X:
		 for (int i = 0; i < SIZE; i++) {
			 PointsVector::pointsOnThreads.at(i).lngt /= 2;
		 }
		 break;
	 default:
		 break;
	 }
	 PointsVector::cvr.notify_all();
 }
