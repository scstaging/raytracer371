#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

class Ray;
class SceneInfo;

class Object {

public:
	virtual bool hit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f& hit) = 0;

};