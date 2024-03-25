#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

class Camera {

public:
	Camera(Eigen::Vector3f lookat, Eigen::Vector3f up, Eigen::Vector3f centre);
	Eigen::Vector3f lookat, up, centre;

};