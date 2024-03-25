#include "Camera.h"

Camera::Camera(Eigen::Vector3f lookat, Eigen::Vector3f up, Eigen::Vector3f centre)
{
	this->lookat = lookat;
	this->up = up;
	this->centre = centre;
}