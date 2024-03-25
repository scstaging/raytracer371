#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

class Light {

public:
	Light();
	Light(std::string t, Eigen::Vector3f c, Eigen::Vector3f d, Eigen::Vector3f s);

	// Attributes
	std::string type;
	Eigen::Vector3f centre;
	Eigen::Vector3f diffuse;
	Eigen::Vector3f specular;
};