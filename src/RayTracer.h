#pragma once

#include "../external/json.hpp"
#include <iostream>
#include <Eigen/Core>
#include <Eigen/Dense>

#include "json.hpp"

#include <sstream>
#include "SceneInfo.h"
#include "Camera.h"
#include "Ray.h"
#include <vector>

#include <fstream>
#include <cstdio>
#include <string>

class RayTracer {

	public:
	RayTracer(nlohmann::json& j);

	// Methods
	void run();
	Eigen::Vector2f pixelProjection(unsigned int x, unsigned int y, SceneInfo* sceneInfo);
	Eigen::Vector3f setRayColor(Ray ray, SceneInfo* sceneInfo);
	int save_ppm(std::string file_name, const std::vector<double>& buffer, int dimx, int dimy, SceneInfo* sceneInfo, Camera* camera);
	Ray createRay(Camera* camera, Eigen::Vector2f projectedPixel);
	bool sphereHit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f &hit, Geometry* sphere);
	Eigen::Vector3f rgbColor(Ray ray);
	Eigen::Vector2f solveQuadratic(float discrim, float a, float b);
	Eigen::Vector3f getHit(Eigen::Vector3f o, Eigen::Vector3f d, Eigen::Vector2f q);
	Eigen::Vector3f phongReflection(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f hit, Geometry* sphere, Light* light);
	bool rectangleHit(Ray ray, Rectangle* rect, Eigen::Vector3f& rectHit);
	Eigen::Vector3f rectPhong(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f hit, Rectangle* rect, Light* light);

	nlohmann::json jsonObj;

};