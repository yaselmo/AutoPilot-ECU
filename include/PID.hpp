
#pragma once

#include <algorithm>
#include <stdexcept>

class PID {
public:
    PID(double kp, double ki, double kd)
    : kp_(kp), ki_(ki), kd_(kd) {}

    double update(double target, double measured, double dt) {
        if (dt <= 0.0) {
            throw std::invalid_argument("dt must be positive");
        }

        const double error = target - measured;

        integral_ = std::clamp(
            integral_ + error * dt, -10.0, 10.0
        );

        const double derivative =
        first_ ? 0.0 : (error - lastError_) / dt;

        lastError_ = error;
        first_ = false;

        return std::clamp(
            kp_ * error + ki_ * integral_ + kd_ * derivative,
            -1.0, 1.0
        );
    }

    void reset() {
        integral_ = 0.0;
        lastError_ = 0.0;
        first_ = true;
    }

private:
    double kp_;
    double ki_;
    double kd_;

    double integral_ = 0.0;
    double lastError_ = 0.0;
    bool first_ = true;
};
