#include "Output.h"

Output::Output()
{

}

Output::Output(std::string fn, std::array<int, 2> s, Eigen::Vector3f lookat, Eigen::Vector3f up, Eigen::Vector3f centre, float fov, Eigen::Vector3f ai)
{
	filename = fn;
	size = s;
	this->lookat = lookat;
	this->up = up;
	this->centre = centre;
	this->fov = fov;
	this->ai = ai;
}