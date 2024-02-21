#include "Plane.h"

Plane::Plane(std::string id, PlaneType type, int capacity)
:_id{id},_type{type},_capacity{capacity}
{
}

std::ostream &operator<<(std::ostream &os, const Plane &rhs) {

    os << "_id: " << rhs._id<<std::endl;
    os<< " _type: " << static_cast<int>(rhs._type)<<std::endl;
    os<< " _capacity: " << rhs._capacity<<std::endl;

    return os;
}

