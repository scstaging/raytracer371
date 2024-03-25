#pragma once

#include "Geometry.h"
#include "Light.h"
#include "Output.h"
#include <iostream>
#include "json.hpp"
#include "simpleppm.h"
#include <Eigen/Core>
#include <Eigen/Dense>
#include <sstream>
#include <vector>
#include "Rectangle.h"
#include "Sphere.h"
#include "AreaLight.h"
#include <memory>

class SceneInfo {

public:
	// Constructor
	SceneInfo(const nlohmann::json& o);

	// Scene Properties
	std::vector<Geometry*> spheres;
	std::vector<Rectangle*> rectangles;
	std::vector<Light*> lights;
	std::vector<AreaLight*> arealights;
	std::vector<std::unique_ptr<Object>> hittableObjects;
	Output* output;
	nlohmann::json jsonObj;

	// Parse Scene
	void parseAll();
	void parseGeometries();
	void parseLights();
	void parseOutput();

};