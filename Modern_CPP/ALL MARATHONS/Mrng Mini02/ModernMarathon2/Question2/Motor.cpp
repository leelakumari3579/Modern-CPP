#include "Motor.h"

Motor::Motor(float time_0_to_100, float maxPower, int maxTorque)
:_time_0_to_100(time_0_to_100),_maxPower(maxPower),_maxTorque(maxTorque)
{
    
}
float Motor::operator+(Motor & m)
{
    return this->maxPower()+m.maxPower();
}
std::ostream &operator<<(std::ostream &os, const Motor &rhs)
{
    os << "_time_0_to_100: " << rhs._time_0_to_100
       << " _maxPower: " << rhs._maxPower
       << " _maxTorque: " << rhs._maxTorque;
    return os;
}
