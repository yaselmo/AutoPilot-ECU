
#include <algorithm>
#include <iostream>

#include "PID.hpp"

int main() {
    PID speedController(0.12, 0.01, 0.02);

    double currentSpeed = 0.0;
    const double targetSpeed = 15.0;
    const double dt = 0.02;

    std::cout << "AutoPilot-ECU v0.1.0\n";
    std::cout << "Starting speed controller...\n\n";

    for (int step = 0; step < 500; ++step) {
        double control = speedController.update(
            targetSpeed, currentSpeed, dt
        );

        double throttle = std::max(0.0, control);
        double brake = std::max(0.0, -control);

        // Simplified vehicle physics.
        double acceleration =
        3.0 * throttle -
        6.0 * brake -
        0.02 * currentSpeed;

        currentSpeed = std::max(
            0.0,
            currentSpeed + acceleration * dt
        );

        if (step % 25 == 0) {
            std::cout
            << "Speed: " << currentSpeed
            << " m/s | Target: " << targetSpeed
            << " | Throttle: " << throttle
            << " | Brake: " << brake
            << "\n";
        }
    }

    return 0;
}
