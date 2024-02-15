#include "Motor.h"

Motor::Motor(float time_0_to_100, float maxPower, unsigned int maxTorque)
:_time_0_to_100{time_0_to_100},_maxPower{maxPower},_maxTorque{maxTorque}
{

}
std::ostream &operator<<(std::ostream &os, const Motor &rhs) {

os<<"-----------------------------------------------------------"<<std::endl;
    os << "_time_0_to_100: " << rhs._time_0_to_100<<std::endl;
    os << " _maxPower: " << rhs._maxPower<<std::endl;
    os<< " _maxTorque: " << rhs._maxTorque<<std::endl;

os<<"-----------------------------------------------------------"<<std::endl;
    return os;
}
