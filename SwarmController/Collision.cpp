#include "Collision.h"
using namespace Eigen;
bool* Collision::getAvailDirs(string name)
{

	msr::airlib::LidarData lidar1 = PointsVector::client.getLidarData("MyLidar1", name);
	msr::airlib::LidarData lidar2 = PointsVector::client.getLidarData("MyLidar2", name);



	Map<Matrix< float, Dynamic, Dynamic, RowMajor >> cloudData1(&lidar1.point_cloud[0], lidar1.point_cloud.size() / 3, 3);
	Map<Matrix< float, Dynamic, Dynamic, RowMajor >> cloudData2(&lidar2.point_cloud[0], lidar2.point_cloud.size() / 3, 3);




	MatrixXf totalData(cloudData1.rows() + cloudData2.rows(), cloudData1.cols());
	totalData << cloudData1, cloudData2;




	Vector3f pos = PointsVector::client.getMultirotorState(name).getPosition();
	MatrixXf result = totalData.rowwise() + (-pos).transpose();

	MatrixX2f finalMatrixE(result.rows(), 2);

	for (int i = 0; i < result.rows(); i++)
	{


	}


	MatrixXf z_powMat = result.leftCols(2).array().pow(2);
	MatrixXf z_col = (z_powMat.col(1).array() + z_powMat.col(0).array()).cwiseSqrt();

	MatrixXf z_angles = z_col.binaryExpr(result.col(2), [](float a, float b) { return std::atan2(a, b); });

	MatrixXf x_angles = result.col(1).binaryExpr(result.col(0), [](float a, float b) { return std::atan2(a, b) < 0 ? std::atan2(a, b) + (M_PI * 2) : std::atan2(a, b); });
	//std::cout << x_angles*180/M_PI << std::endl;

	MatrixXf finalMatrix(x_angles.rows(), x_angles.cols() + z_angles.cols());
	finalMatrix << z_angles, x_angles;
	//std::cout << z_angles * 180 / M_PI << std::endl;
	std::vector<float> container;
	bool* directions = new bool[38]; // binning yapilacak
	bool up = true, down = true;
	for (int i = 0; i < finalMatrix.rows(); i++)
	{
		//if (strcmp(name.c_str(), "SwarmNode1") == 0 && finalMatrix.size() < 40) {
			//std::cout << finalMatrix << std::endl;
			//std::cout << "---------------" << std::endl;
		//}
		if (!std::isnan(finalMatrix(i, 0)) && !std::isinf(finalMatrix(i, 0))) {
			if (finalMatrix(i, 0) <= (3 * M_PI / 4) && finalMatrix(i, 0) >= (M_PI / 4)) {

				container.push_back(finalMatrix(i, 0) * 180 / M_PI);
				container.push_back(finalMatrix(i, 1) * 180 / M_PI);


			}
			else if (up || down) {
				if (finalMatrix(i, 0) > 3 * M_PI / 4) {
					up = false;
				}
				else {
					down = false;
				}
			}
		}
	}
	directions[36] = up;
	directions[37] = down;
	Map<Matrix<float, Dynamic, Dynamic, RowMajor>> sel(container.data(), container.size() / 2, 2);
	for (int i = 0; i < sel.rows(); i++)
	{
		if (!std::isnan(sel(i, 1)) && !std::isinf(sel(i, 1))) {
			directions[int(int(sel(i, 1))  / 10)] = false;
			for (int j = 1; j < 5; j++) {
				directions[(int(int(sel(i, 1)) / 10) - j + 36) % 36] = false;
				directions[(int(int(sel(i, 1)) / 10) + j) % 36] = false;
			}
		}
	}
	/*for (int i = 0; i < x_angles.rows(); i++)
	{
		std::cout << x_angles(i, 0) * 180 / M_PI << std::endl;
	}*/



	return directions;

}

Vector3f Collision::getManeVec(msr::airlib::string name, Vector3f unitTargetVec, float yaw)
{
	bool* directions = new bool[38];
	directions = Collision::getAvailDirs(name);
	Matrix3f rotMatrix;
	Vector3f maneuver = unitTargetVec;
	float x_angle = acos(unitTargetVec.x() / sqrt(pow(unitTargetVec.y(), 2) + pow(unitTargetVec.z(), 2)));
	//if (strcmp(name.c_str(), "SwarmNode1") == 0) {
		//for (size_t i = 0; i < 8; i++)
		//{
		//	if (directions[i]) {
		//		std::cout << "true:" + std::to_string(i * 45) << std::endl;
		//	}
		//	else
		//		std::cout << "false:" + std::to_string(i * 45) << std::endl;
	//
		//}
		//std::cout << "yaw : "+ std::to_string(yaw*180/M_PI) + "------" << std::endl;
	//}
	if (!std::isnan(x_angle) && !std::isinf(x_angle)) {
		int directionIndex = int((x_angle * 180 / M_PI) / 10);
		//std::cout << "my index : " + std::to_string(directionIndex) << std::endl;
		// check bins with x_angle
		if (!directions[directionIndex]) {
			int counter = 1;
			while ((!directions[(directionIndex + counter) % 36] || !directions[(directionIndex - counter+36) % 36]) && counter < 18) {
				counter++;
			}
			if (directions[(directionIndex + counter) % 36]) {
				// turn vector on x-axis with theta = ((directionIndex + counter) % 8)*45)
				//AngleAxis<float> rotMat( counter % 8 * 45 * M_PI / 180, Vector3f(1, 0, 0));// !
				Matrix3f rotMatrix;
				rotMatrix << float(cos(((counter + 35) % 36)*M_PI / 18)), float(-sin(((counter + 35) % 36)*M_PI / 18)), 0,
					float(sin(((counter + 35) % 36)*M_PI / 18)), float(cos(((counter + 35) % 36)*M_PI / 18)), 0,
					0, 0, 1;
				maneuver = rotMatrix * maneuver;


			}
			else if (directions[abs(directionIndex - counter) % 36]) {
				// turn vector on x-axis with theta = ((directionIndex + counter) % 8)*45)
				//AngleAxis<float> rotMat( counter % 8 * 45 * M_PI / 180, Vector3f(1, 0, 0));// !
				Matrix3f rotMatrix;
				rotMatrix << float(cos(-((counter + 1) % 36)*M_PI / 18)), float(-sin(-((counter + 1) % 36)*M_PI / 18)), 0,
					float(sin(-((counter + 1) % 36)*M_PI / 18)), float(cos(-((counter + 1) % 36)*M_PI / 18)), 0,
					0, 0, 1;
				maneuver = rotMatrix * maneuver;

			}
			else {
				maneuver(0) = 0;
				maneuver(1) = 0;
				if (directions[36])
					maneuver(2) = -1;
				else if (directions[37])
					maneuver(2) = 1;
			}
			//std::cout << std::to_string((counter ) * 45) + "  degrees rotated" << std::endl;
		}
	}

	if ((unitTargetVec.z() < 0 && !directions[36]) || (unitTargetVec.z() > 0 && !directions[37])) {
		maneuver(2) = 0;
	}


	return maneuver;

}





