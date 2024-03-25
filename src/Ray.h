#pragma once

#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

class Ray {

public:
	Ray(Eigen::Vector3f o, Eigen::Vector3f d);

	Eigen::Vector3f origin;
	Eigen::Vector3f direction;
	Eigen::Vector3f color;
	//	Ray -> P(t) = origin + k*direction
	//	K scales point on Ray
	Eigen::Vector3f rayAtK(double k);

};