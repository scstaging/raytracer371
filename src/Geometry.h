#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

class Geometry {

public:
	Geometry();
	Geometry(std::string t, Eigen::Vector3f c, int r, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc);
	
	// Attributes
	std::string type;
	Eigen::Vector3f centre;
	int radius;

	// Local illumination attributes
	Eigen::Vector3f ac, dc, sc;
	float ka, kd, ks, pc;

};