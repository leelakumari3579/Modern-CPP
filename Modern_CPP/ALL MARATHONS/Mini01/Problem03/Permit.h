#ifndef PERMIT_H
#define PERMIT_H

#include <string>
#include <ostream>
#include "PermitType.h"

class Permit {
    private:
        std::string _serialNumber;
        PermitType _permitType;
        int _permitTimeLeft;

    public:

        // Initial Setup
        Permit() = delete;
        Permit(const Permit&) = delete;
        Permit(Permit&&) = delete;
        Permit& operator=(const Permit&) = delete;
        Permit& operator=(Permit&&) = delete;
        ~Permit() = default;

        // Parameterized Constructor
        Permit(std::string serialNumber, PermitType permitType, int permitTimeLeft);

        // Getters
        std::string serialNumber() const { return _serialNumber; }
        PermitType permitType() const { return _permitType; }
        int permitTimeLeft() const { return _permitTimeLeft; }

        // Overriding Output Stream Operator
        friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
