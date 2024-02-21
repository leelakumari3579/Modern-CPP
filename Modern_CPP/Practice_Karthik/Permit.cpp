#include "Permit.hpp"
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serailNumber: " << rhs._serailNumber
       << " _permitType: " << static_cast<int>(rhs._permitType)
       << " _permitTimeLeft: " << rhs._permitTimeLeft;
    return os;
}


Permit::Permit(std::string serialNumber, PermitType pType, int permitTimeLeft):
_serailNumber(serialNumber), _permitType(pType), _permitTimeLeft(permitTimeLeft) {}
