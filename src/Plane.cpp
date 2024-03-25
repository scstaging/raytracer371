#include "Plane.h"

Plane::Plane() : normal(Eigen::Vector3f(0.0f, 0.0f, 0.0f)), distance(0.0f) {}

Plane::Plane(const Eigen::Vector3f& point1, const Eigen::Vector3f& point2, const Eigen::Vector3f& point3) {
    // Calculate the normal vector of the plane using the cross product of two vectors on the plane
    Eigen::Vector3f v1 = (point2 - point1).normalized();
    Eigen::Vector3f v2 = (point3 - point1).normalized();
    normal = v1.cross(v2).normalized();

    // Calculate the distance from the origin to the plane
    distance = -normal.dot(point1);
}

Plane::~Plane() {}

Eigen::Vector3f Plane::intersect(const Ray ray) const {
    float denom = normal.dot(ray.direction);
    // Calculate the distance along the ray to the intersection point
    
    float t = -(normal.dot(ray.origin) + distance) / denom;

    // Calculate the intersection point
    Eigen::Vector3f intersectionPoint = ray.origin + ray.direction * t;

    // Returns
    return intersectionPoint;
}