#include "RayTracer.h"

// ********* CLASS DEFINITIONS ********* //

double degreesToRadians(double degrees);

RayTracer::RayTracer(nlohmann::json& j)
{
	jsonObj = j;
}

void RayTracer::run()
{
	std::string filename = jsonObj["output"][0]["filename"];
	int dimx = jsonObj["output"][0]["size"][0];
	int dimy = jsonObj["output"][0]["size"][1];
	std::vector<double> buffer(3 * dimx * dimy);

	// Parses and stores all scene info
	SceneInfo* sceneInfo = new SceneInfo(jsonObj);
	sceneInfo->parseAll();

	// Camera Instantiation
	Camera* camera = new Camera(sceneInfo->output->lookat, sceneInfo->output->up, sceneInfo->output->centre);

	// Saves file to PPM
	save_ppm(filename, buffer, dimx, dimy, sceneInfo, camera);
}

Eigen::Vector2f RayTracer::pixelProjection(unsigned int x, unsigned int y, SceneInfo* sceneInfo)
{
	// Extract scene components
	const Eigen::Vector3f lookat = sceneInfo->output->lookat;
	const Eigen::Vector3f up = sceneInfo->output->up;
	Eigen::Vector3f right = up.cross(lookat).normalized();
	const Eigen::Vector3f centre = sceneInfo->output->centre;
	const unsigned int sceneWidth = sceneInfo->output->size[0];
	const unsigned int sceneHeight = sceneInfo->output->size[1];
	const Eigen::Vector3f sceneCentre = centre + lookat;

	// Calculate aspect ratio
	float aspectRatio = static_cast<float>(sceneWidth) / sceneHeight;

	// Calculate FOV in radians
	float fovRadians = degreesToRadians(sceneInfo->output->fov);

	// Calculate half-width and half-height of the view plane
	const float halfHeight = std::tan(fovRadians / 2.0f);
	const float halfWidth = aspectRatio * halfHeight;

	// Calculate pixel sizes
	const float pixelSizeX = (2.0f * halfWidth) / sceneWidth;
	const float pixelSizeY = (2.0f * halfHeight) / sceneHeight;

	// Compute top-left point of the viewport
	const Eigen::Vector3f topLeft = sceneCentre + (up * halfHeight) - (right * halfWidth);

	// Calculate pixel position relative to top-left corner of the viewport
	const Eigen::Vector3f pixelPositionX = topLeft + x * pixelSizeX * right;
	const Eigen::Vector3f pixelPositionY = topLeft - y * pixelSizeY * up;

	return Eigen::Vector2f(pixelPositionX[0], pixelPositionY[1]);
}

Ray RayTracer::createRay(Camera* camera, Eigen::Vector2f projectedPixel)
{
	Eigen::Vector3f pixelCentre(projectedPixel[0], projectedPixel[1], camera->lookat[2]);
	Eigen::Vector3f direction = pixelCentre - camera->centre;
	direction = direction.normalized();
	Ray ray(camera->centre, direction);
	return ray;
}

Eigen::Vector3f RayTracer::setRayColor(Ray ray, SceneInfo* sceneInfo)
{
	for (int i = 0; i < sceneInfo->spheres.size(); i++)
	{
		Eigen::Vector3f hit;

		if (sphereHit(ray, sceneInfo, hit, sceneInfo->spheres[i]))
		{
			// Lights are additive
			Eigen::Vector3f color(0.0f, 0.0f, 0.0f);
			for (int j = 0; j < sceneInfo->lights.size(); j++)
			{
				color += phongReflection(ray, sceneInfo, hit, sceneInfo->spheres[i], sceneInfo->lights[j]);
			}

			// Clamps
			color = color.cwiseMin(Eigen::Vector3f(255.0f, 255.0f, 255.0f)).cwiseMax(Eigen::Vector3f(0.0f, 0.0f, 0.0f));

			// Return final combinational color
			return color;
		}
	}

	for (int i = 0; i < sceneInfo->rectangles.size(); i++)
	{
		Eigen::Vector3f rectHit;

		if (rectangleHit(ray, sceneInfo->rectangles[i], rectHit))
		{
			// Lights are additive
			Eigen::Vector3f color(0.0f, 0.0f, 0.0f);
			for (int j = 0; j < sceneInfo->lights.size(); j++)
			{
				color += rectPhong(ray, sceneInfo, rectHit, sceneInfo->rectangles[i], sceneInfo->lights[j]);
			}

			// Clamps
			color = color.cwiseMin(Eigen::Vector3f(255.0f, 255.0f, 255.0f)).cwiseMax(Eigen::Vector3f(0.0f, 0.0f, 0.0f));

			// Return final combinational color
			return color;
		}
	}

	Eigen::Vector3f color(255.0, 255.0, 255.0);
	return color;
}

int RayTracer::save_ppm(std::string file_name, const std::vector<double>& buffer, int dimx, int dimy, SceneInfo* sceneInfo, Camera* camera) {

	std::ofstream ofs(file_name, std::ios_base::out | std::ios_base::binary);
	ofs << "P6" << std::endl << dimx << ' ' << dimy << std::endl << "255" << std::endl;

	for (unsigned int j = 0; j < dimy; ++j)
		for (unsigned int i = 0; i < dimx; ++i)
		{
			Eigen::Vector2f projectedPixel = pixelProjection(i, j, sceneInfo);
			Ray ray = createRay(camera, projectedPixel);
			ray.color = setRayColor(ray, sceneInfo);
			ofs << (char) ray.color[0] << (char) ray.color[1] << (char) ray.color[2];
		}

	ofs.close();

	return 0;
}

bool RayTracer::sphereHit(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f &hit, Geometry* sphere)
{
	Eigen::Vector3f centre = sphere->centre;
	float radius = (float) sphere->radius;

	// (t2b dot b) + (2tb dot (A-C)) + ((A-c) dot (A-c)) - r*r
	Eigen::Vector3f z = ray.origin - centre;

	// t^2 term
	float a = ray.direction.dot(ray.direction);

	// t term
	float b = 2.0 * z.dot(ray.direction);

	// scaler term
	float c = z.dot(z) - radius*radius;

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

Eigen::Vector3f RayTracer::rgbColor(Ray ray)
{
	int r = (int)(ray.direction[0] * 255.0f);
	int g = (int)(ray.direction[1] * 255.0f);
	int b = (int)(ray.direction[2] * 255.0f);

	Eigen::Vector3f color(r, g, b);

	return color;
}

Eigen::Vector2f RayTracer::solveQuadratic(float discrim, float a, float b)
{
	// ( -b +- sqrt(b*b-4*a*c) ) / 2
	float q1 = (-b + std::sqrt(discrim)) / (2.0f * a);
	float q2 = (-b - std::sqrt(discrim)) / (2.0f * a);

	Eigen::Vector2f qv(q1, q2);

	return qv;
}

Eigen::Vector3f RayTracer::getHit(Eigen::Vector3f o, Eigen::Vector3f d, Eigen::Vector2f q)
{
	// Return closest hit
	Eigen::Vector3f hit(o + d * q[1]);
	return hit;
}

// Phong Reflection
Eigen::Vector3f RayTracer::phongReflection(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f hit, Geometry* sphere, Light* light)
{
	// Scene reflection components
	Eigen::Vector3f ai = sceneInfo->output->ai;

	// Light reflection components
	Eigen::Vector3f ld = light->diffuse;
	Eigen::Vector3f ls = light->specular;

	// Geometric reflection components
	Eigen::Vector3f ac = sphere->ac;
	Eigen::Vector3f dc = sphere->dc;
	Eigen::Vector3f sc = sphere->sc;
	float ka = sphere->ka;
	float kd = sphere->kd;
	float ks = sphere->ks;
	float pc = sphere->pc;

	// Direction vectors
	Eigen::Vector3f N = hit - sphere->centre;
	N = N.normalized();
	Eigen::Vector3f lightPosition = light->centre;
	Eigen::Vector3f viewPosition = sceneInfo->output->centre;

	// Normalize Directions
	Eigen::Vector3f lightDirection = (lightPosition - hit).normalized();
	Eigen::Vector3f viewDirection = (hit - viewPosition).normalized();

	// Reflected vector
	Eigen::Vector3f reflection = lightDirection - (2 * lightDirection.dot(N)) * N;
	reflection = reflection.normalized();

	// Ambient
	Eigen::Vector3f ambient = ai.cwiseProduct(ac) * ka;

	// *** PROBLEM WITH THE AMBIENT COMPONENT *** //
	ambient /= 2.0f;

	// Diffuse 
	Eigen::Vector3f diff = ld.cwiseProduct(dc);

	float diffuse = kd * std::max(N.dot(lightDirection), 0.0f);

	// std::cout << "Diffuse: " << diff << std::endl;

	diff = diffuse * diff;

	// Specular
	Eigen::Vector3f specular = ls.cwiseProduct(sc) * ks * std::pow(std::max(reflection.dot(viewDirection), 0.0f), pc);

	// Phong calculation
	Eigen::Vector3f phong = ambient + diff + specular; // +specular;

	for (int k = 0; k < 3; k++)
	{
		if (phong[k] > 1.0f)
			phong[k] = 1.0f;
		else if (phong[k] < 0.0f)
			phong[k] = 0.0f;
	}

	for (int i = 0; i < 3; i++)
	{
		phong[i] *= 255.0f;
	}

	return phong;
}

bool RayTracer::rectangleHit(Ray ray, Rectangle* rect, Eigen::Vector3f& rectHit)
{
	Plane plane(rect->p1, rect->p2, rect->p3);

	Eigen::Vector3f intersection = plane.intersect(ray);

	if (intersection != Eigen::Vector3f::Zero())
	{
		if (rect->pointInsideRectangle(intersection))
		{
			rectHit = intersection;
			return true;
		}
	}

	return false;
}

// Phong Reflection
Eigen::Vector3f RayTracer::rectPhong(Ray ray, SceneInfo* sceneInfo, Eigen::Vector3f hit, Rectangle* rect, Light* light)
{
	// Scene reflection components
	Eigen::Vector3f ai = sceneInfo->output->ai;

	// Light reflection components
	Eigen::Vector3f ld = light->diffuse;
	Eigen::Vector3f ls = light->specular;

	// Geometric reflection components
	Eigen::Vector3f ac = rect->ac;
	Eigen::Vector3f dc = rect->dc;
	Eigen::Vector3f sc = rect->sc;
	float ka = rect->ka;
	float kd = rect->kd;
	float ks = rect->ks;
	float pc = rect->pc;

	// Rectangle points
	Eigen::Vector3f p1 = rect->p1;
	Eigen::Vector3f p2 = rect->p2;
	Eigen::Vector3f p3 = rect->p3;
	Eigen::Vector3f p4 = rect->p4;

	// Rectangle Sides
	Eigen::Vector3f side1 = p2 - p1;
	Eigen::Vector3f side2 = p3 - p1;

	// Direction vectors
	Eigen::Vector3f N = side1.cross(side2);
	N = N.normalized();
	Eigen::Vector3f lightPosition = light->centre;
	Eigen::Vector3f viewPosition = sceneInfo->output->centre;

	// Normalize Directions
	Eigen::Vector3f lightDirection = (lightPosition - hit).normalized();
	Eigen::Vector3f viewDirection = (hit).normalized();

	// Reflected vector
	Eigen::Vector3f reflection = lightDirection - (2 * lightDirection.dot(N)) * N;
	reflection = reflection.normalized();

	// Ambient
	Eigen::Vector3f ambient = ai.cwiseProduct(ac) * ka;

	// Diffuse 
	Eigen::Vector3f diff = ld.cwiseProduct(dc);

	float diffuse = kd * std::max(N.dot(lightDirection), 0.0f);

	diff = diffuse * diff;

	// Specular
	Eigen::Vector3f specular = ls.cwiseProduct(sc) * ks * std::pow(std::max(reflection.dot(viewDirection), 0.0f), pc);

	// Phong calculation
	Eigen::Vector3f phong = ambient + diff + specular; // +specular;

	for (int k = 0; k < 3; k++)
	{
		if (phong[k] > 1.0f)
			phong[k] = 1.0f;
		else if (phong[k] < 0.0f)
			phong[k] = 0.0f;
	}

	for (int i = 0; i < 3; i++)
	{
		phong[i] *= 255.0f;
	}

	return phong;
}

// Function to convert degrees to radians
double degreesToRadians(double degrees) {
	return degrees * 3.14159f / 180.0;
}