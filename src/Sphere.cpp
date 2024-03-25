#include "Sphere.h"

Sphere::Sphere()
{

}

Sphere::Sphere(std::string t, Eigen::Vector3f c, int r, Eigen::Vector3f ac, Eigen::Vector3f dc, Eigen::Vector3f sc, float ka, float kd, float ks, float pc)
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

bool Sphere::hit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f& hit)
{
	Eigen::Vector3f centre = this->centre;
	float radius = (float) this->radius;

	// (t2b dot b) + (2tb dot (A-C)) + ((A-c) dot (A-c)) - r*r
	Eigen::Vector3f z = ray.origin - centre;

	// t^2 term
	float a = ray.direction.dot(ray.direction);

	// t term
	float b = 2.0 * z.dot(ray.direction);

	// scaler term
	float c = z.dot(z) - radius * radius;

	// Calculate discriminant to see if POI exist
	float disc = b * b - 4 * a * c;

	// Only if POI exist
	if (disc >= 0)
	{
		Eigen::Vector2f q = solveQuadratic(disc, a, b);
		hit = getHit(ray.origin, ray.direction, q);
	}

	// Return
	return disc >= 0;
}

Eigen::Vector2f Sphere::solveQuadratic(float discrim, float a, float b)
{
	// ( -b +- sqrt(b*b-4*a*c) ) / 2
	float q1 = (-b + std::sqrt(discrim)) / (2.0f * a);
	float q2 = (-b - std::sqrt(discrim)) / (2.0f * a);

	Eigen::Vector2f qv(q1, q2);

	return qv;
}

Eigen::Vector3f Sphere::getHit(Eigen::Vector3f o, Eigen::Vector3f d, Eigen::Vector2f q)
{
	// Return closest hit
	Eigen::Vector3f hit(o + d * q[1]);
	return hit;
}