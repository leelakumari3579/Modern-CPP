#ifndef MOTOR_H
#define MOTOR_H
#include <ostream>

class Motor
{
private:
    float _time_0_to_100;
    float _maxPower;
    unsigned int _maxTorque;

public:

    Motor(float time_0_to_100,float maxPower,unsigned int maxTorque);
    

    Motor() =delete;
    Motor(const Motor&)=default;
    Motor(Motor&&)=default;
    Motor& operator=(const Motor&)=default;
    Motor& operator=(Motor&&)=default;
    ~Motor()=default;

    float time0To_100() const { return _time_0_to_100; }

    float maxPower() const { return _maxPower; }
    void setMaxPower(float maxPower) { _maxPower = maxPower; }

    unsigned int maxTorque() const { return _maxTorque; }
    void setMaxTorque(unsigned int maxTorque) { _maxTorque = maxTorque; }

    friend std::ostream &operator<<(std::ostream &os, const Motor &rhs);

    float operator+(Motor& m)
    {
        return this->maxPower()+m.maxPower();
    }
   
};

#endif // MOTOR_H
