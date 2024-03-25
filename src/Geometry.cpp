#include "Geometry.h"

Geometry::Geometry()
{

}

Geometry::Geometry(std::string t, Eigen::Vector3f c, int r, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc)
{
	type = t;
	centre = c;
	radius = r;
	this->ac = ac;
	this->dc = dc;
	this->sc = sc;
	this->ka = ka;
	this->kd = kd;
	this->ks = ks;
	this->pc = pc;
}