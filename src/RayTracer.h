#include "../external/json.hpp"

class RayTracer {

	public:
	RayTracer(nlohmann::json& j);
	void run();

};
