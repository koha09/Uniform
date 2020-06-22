#include <uniform/core/physics/physics.hpp>

#include <cmath>

double UNIFORM_API Uniform::Physics::calculate_distance(Uniform::Vector3d position_1, Uniform::Vector3d position_2) {
    return std::sqrt(
		std::pow(position_2.x - position_1.x, 2) +
		std::pow(position_2.y - position_1.y, 2) +
		std::pow(position_2.z - position_1.z, 2)
	);
}