#include "Light.h"

Light::Light()
{

}

Light::Light(std::string t, Eigen::Vector3f c, Eigen::Vector3f d, Eigen::Vector3f s)
{
	type = t;
	centre = c;
	diffuse = d;
	specular = s;
}