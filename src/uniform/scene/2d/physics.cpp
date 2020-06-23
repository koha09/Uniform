#include <uniform/scene/2d/physics.hpp>

#include <cmath>

double Uniform::Physics::calculate_distance(Uniform::Vector2d position_1, Uniform::Vector2d position_2) {
	return std::sqrt(
		std::pow(position_2.x - position_1.x, 2) +
		std::pow(position_2.y - position_1.y, 2)
	);
}