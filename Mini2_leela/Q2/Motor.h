#ifndef MOTOR_H
#define MOTOR_H
#include <ostream>

class Motor
{
private:
    float _time_0_to_100 {0.0f};
    float _maxPower {0.0f};
    int _maxTorque {0};
public:
    Motor() = default;
    Motor(const Motor &) = default;
    Motor &operator=(const Motor &) = delete;
    Motor &operator=(Motor &&) = delete;
    Motor(Motor &&) = default;
    ~Motor() = default;  

    Motor(float time, float maxPower, int maxTorque);
    Motor operator+(Motor &m1);

    float time0To_100() const { return _time_0_to_100; }
    void setTime0To_100(float time_0_to_100) { _time_0_to_100 = time_0_to_100; }

    float maxPower() const { return _maxPower; }
    void setMaxPower(float maxPower) { _maxPower = maxPower; }

    int maxTorque() const { return _maxTorque; }
    void setMaxTorque(int maxTorque) { _maxTorque = maxTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Motor &rhs);
};



#endif // MOTOR_H
