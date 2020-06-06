#include <logger/logger.hpp>

#include <uniform/core/math/vector2.hpp>
#include <uniform/core/math/vector3.hpp>

#include <cassert>

using namespace Uniform;

int main() {
    Vector2i v1(10, 10), v2(10, 10);

    v1 -= v2, v1 -= 10;
    assert(
        (v1 - v2).x == -20 &&
        (v1 - v2).y == -20
    );

    LOG_INFORMATION() << "[assert #1]: [" << v1.x << ", " << v1.y << "]\n";

    v1 += v2, v1 += 10;
    assert(
        (v1 + v2).x == 20 &&
        (v1 + v2).y == 20
    );

    LOG_INFORMATION() << "[assert #2]: [" << v1.x << ", " << v1.y << "]\n";

    v1 /= v2, v1 /= 1;
    assert(
        (v2 / v1).x == 10 &&
        (v2 / v1).y == 10
    );

    LOG_INFORMATION() << "[assert #3]: [" << v1.x << ", " << v1.y << "]\n";

    v1 *= v2, v1 *= 1;
    assert(
        (v1 * v2).x == 100 &&
        (v1 * v2).y == 100
    );

    LOG_INFORMATION() << "[assert #4]: [" << v1.x << ", " << v1.y << "]\n";

    return 0;
}