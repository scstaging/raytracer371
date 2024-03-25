#include "Ray.h"

Ray::Ray(Eigen::Vector3f o, Eigen::Vector3f d)
{
	origin = o;
	direction = d;
}

Eigen::Vector3f Ray::rayAtK(double k)
{
	return origin + k * direction;
}