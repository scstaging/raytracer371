#pragma once

#include "Object.h"
#include "Plane.h"

class Rectangle : public Object {

public:
	Rectangle(Eigen::Vector3f p1, Eigen::Vector3f p2, Eigen::Vector3f p3, Eigen::Vector3f p4, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc);

	// Attributes
	Eigen::Vector3f p1, p2, p3, p4;

	// Local illumination attributes
	Eigen::Vector3f ac, dc, sc;
	float ka, kd, ks, pc;

	// Overwrite
	bool hit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f& rectHit);

	// Methods
	bool pointInsideRectangle(const Eigen::Vector3f& intersect);

};