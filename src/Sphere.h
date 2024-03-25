#pragma once

#include "Object.h"

class Sphere : public Object {

public:
	Sphere();
	Sphere(std::string t, Eigen::Vector3f c, int r, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc);

	// Attributes
	std::string type;
	Eigen::Vector3f centre;
	int radius;

	// Local illumination attributes
	Eigen::Vector3f ac, dc, sc;
	float ka, kd, ks, pc;

	// Methods
	Eigen::Vector2f solveQuadratic(float discrim, float a, float b);
	Eigen::Vector3f getHit(Eigen::Vector3f o, Eigen::Vector3f d, Eigen::Vector2f q);

	// Overwrite
	bool hit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f& hit);

};