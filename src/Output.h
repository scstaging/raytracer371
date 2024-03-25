#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

class Output {

public:
	Output();
	Output(std::string fn, std::array<int, 2> s, Eigen::Vector3f lookat, Eigen::Vector3f up, Eigen::Vector3f centre, float fov, Eigen::Vector3f ai);
	std::string filename;
	std::array<int, 2> size;
	Eigen::Vector3f lookat, up, centre;
	float fov;
	Eigen::Vector3f ai;

};