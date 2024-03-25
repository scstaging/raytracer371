#include <Eigen/Core>
#include <Eigen/Dense>
#include <iostream>

class AreaLight {

public:
    Eigen::Vector3f p1, p2, p3, p4;
    Eigen::Vector3f id, is;
    bool useCentre;
    float n;
	AreaLight(Eigen::Vector3f p1, Eigen::Vector3f p2, Eigen::Vector3f p3, Eigen::Vector3f p4, Eigen::Vector3f id, Eigen::Vector3f is, bool useCentre, float n);

};