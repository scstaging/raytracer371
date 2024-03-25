#include "Rectangle.h"

Rectangle::Rectangle(Eigen::Vector3f p1, Eigen::Vector3f p2, Eigen::Vector3f p3, Eigen::Vector3f p4, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->ac = ac;
	this->dc = dc;
	this->sc = sc;
	this->ka = ka;
	this->kd = kd;
	this->ks = ks;
	this->pc = pc;
}

bool Rectangle::hit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f& rectHit)
{
	Plane plane(this->p1, this->p2, this->p3);

	Eigen::Vector3f intersection = plane.intersect(ray);

	if (intersection != Eigen::Vector3f::Zero())
	{
		if (this->pointInsideRectangle(intersection))
		{
			rectHit = intersection;
			return true;
		}
	}

	return false;
}

// Function to check if a point is inside a rectangle
bool Rectangle::pointInsideRectangle(const Eigen::Vector3f& intersect) {
	
	// Calculate vectors representing the sides of the rectangle
	Eigen::Vector3f side1 = p2 - p1;
	Eigen::Vector3f side2 = p3 - p2;
	Eigen::Vector3f side3 = p4 - p3;
	Eigen::Vector3f side4 = p1 - p4;

	// Calculate vectors representing the point to the corners of the rectangle
	Eigen::Vector3f vectorToPoint1 = intersect - p1;
	Eigen::Vector3f vectorToPoint2 = intersect - p2;
	Eigen::Vector3f vectorToPoint3 = intersect - p3;
	Eigen::Vector3f vectorToPoint4 = intersect - p4;

	// Calculate dot products to determine if the point is inside the rectangle
	float dot1 = side1.dot(vectorToPoint1);
	float dot2 = side2.dot(vectorToPoint2);
	float dot3 = side3.dot(vectorToPoint3);
	float dot4 = side4.dot(vectorToPoint4);

	return (dot1 > 0 && dot2 > 0 && dot3 > 0 && dot4 > 0) || (dot1 < 0 && dot2 < 0 && dot3 < 0 && dot4 < 0);

}