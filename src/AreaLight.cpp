#include "AreaLight.h"

AreaLight::AreaLight(Eigen::Vector3f p1, Eigen::Vector3f p2, Eigen::Vector3f p3, Eigen::Vector3f p4, Eigen::Vector3f id, Eigen::Vector3f is, bool useCentre, float n)
{
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	this->p4 = p4;
	this->id = id;
	this->is = is;
	this->useCentre = useCentre;
	this->n = n;
}