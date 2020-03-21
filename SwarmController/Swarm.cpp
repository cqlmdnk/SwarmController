#include "Swarm.h"
#include <string>
#include <algorithm>
#include <random>
#include <conio.h>


static int size;

#define PI 3.14159265
void Swarm::addNode(SwarmNode node)
{
}

void Swarm::go(std::vector<SwarmNode*> swarmVec)
{


	for (auto node : swarmVec) {

		string name = node->getName();
		PointsVector::client.enableApiControl(true, name);
		PointsVector::client.armDisarm(true, name);
		PointsVector::client.takeoffAsync(1, name);
		PointsVector::client.moveByVelocityAsync(0, 0, -3, 3, msr::airlib::DrivetrainType::ForwardOnly, msr::airlib::YawMode(false, 0), name);
		PointsVector::client.hoverAsync(name);


	}

	float totalDist = 0.0f;
	while (1) {

		totalDist = 0.0f;

		for (auto node : swarmVec) {

			string name = node->getName();




			int id = getId(name);
			srand(id);



			LandedState isLanded = PointsVector::client.getMultirotorState(name).landed_state;

			if (isLanded == LandedState::Landed) {
				PointsVector::client.takeoffAsync(0.1f, name);

			}

			Vector3f p = PointsVector::pointsOnThreads.at(id) + PointsVector::swarmCenter;
			auto c_p = PointsVector::client.getMultirotorState(name).getPosition();
			Vector3r targetVec = Vector3r((p.x() - c_p.x()), (p.y() - c_p.y()), (p.z() - c_p.z()));
			float dist = sqrt(pow(targetVec.x(), 2) + pow(targetVec.y(), 2) + pow(targetVec.z(), 2));



			//std::cout << std::to_string(id) + " : Moving to poistion... | " + std::to_string(p.x()) + " | " + std::to_string(p.y()) + " | " + std::to_string(p.z()) << std::endl;
			Vector3r unitTargetVec = Vector3r(targetVec.x() / dist, targetVec.y() / dist, targetVec.z() / dist);
			//std::cout << std::to_string(id) + " : Moving with vector..." + std::to_string(unitTargetVec.x()) + "-" + std::to_string(unitTargetVec.y()) + "-" + std::to_string(unitTargetVec.z()) << std::endl;
			float target_yaw = float(atan(targetVec.y() / targetVec.x()) * 180 / PI);
			//PointsVector::client.rotateByYawRateAsync(yaw, 1, name);

			// Collision avoidance 
			totalDist += dist;

			if (dist <= 1.0f) {
				PointsVector::client.hoverAsync(name);
				//std::cout << "Hovering " + name << std::endl;


			}
			else {
				msr::airlib::Quaternionr quat = PointsVector::client.getMultirotorState(name).getOrientation();
				double w = quat.w();
				double x = quat.x();
				double y = quat.y();
				double z = quat.z();

				float yaw = atan2(2.0f * (w * z + x * y), w * w + x * x - y * y - z * z);

				Vector3r maneuverVec = Collision::getManeVec(name, unitTargetVec, yaw);
				float scale = min(log(dist) * 3 + 0.5f, 3);

				PointsVector::client.moveByVelocityAsync(maneuverVec.x() * scale, maneuverVec.y() * scale, maneuverVec.z() * scale, 1, msr::airlib::DrivetrainType::ForwardOnly, msr::airlib::YawMode(false, 0), name);
				//std::cout << name + " : " + std::to_string(dist) << std::endl;

			}
			//PointsVector::client.getMultirotorState().getOrientation();
			//float pitch, roll, yaw2;
			//VectorMath::toEulerianAngle(PointsVector::client.getMultirotorState(name).getOrientation(), pitch, roll, yaw2);

		}
		std::cout << "Total distance : " + std::to_string(totalDist) << std::endl;
		PointsVector::totalDistance = totalDist;
		
		Sleep(100);

	}








	// all threads will be started here



}

int Swarm::getId(string name) {
	size_t last_index = name.find_last_not_of("0123456789");
	return std::stoi((name.substr(last_index + 1))) - 1;
}

