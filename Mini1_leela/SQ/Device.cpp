#include "Device.h"

Device::Device(std::string id, std::string name, float price)
    :_id(id), _name(name), _price(price)
{
}
std::ostream &operator<<(std::ostream &os, const Device &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _price: " << rhs._price;
    return os;
}
