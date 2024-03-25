#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>
#include "Ray.h"

class Plane {

    public:
        Plane();
        Plane(const Eigen::Vector3f& point1, const Eigen::Vector3f& point2, const Eigen::Vector3f& point3);
        ~Plane();

        // Attributes
        Eigen::Vector3f normal;
        float distance; // Distance from origin along the normal

        // Function to find intersection point with a ray
        Eigen::Vector3f intersect(const Ray ray) const;
};