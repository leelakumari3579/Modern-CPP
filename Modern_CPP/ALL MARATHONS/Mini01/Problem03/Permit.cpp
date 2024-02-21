#include <iostream>

#include "Permit.h"

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serialNumber: " << rhs._serialNumber
       << " _permitType: " << static_cast<int>(rhs._permitType)
       << " _permitTimeLeft: " << rhs._permitTimeLeft;
    return os;
}

Permit::Permit(std::string serialNumber, PermitType permitType, int permitTimeLeft):
_serialNumber(serialNumber), _permitType(permitType), _permitTimeLeft(permitTimeLeft) {}
