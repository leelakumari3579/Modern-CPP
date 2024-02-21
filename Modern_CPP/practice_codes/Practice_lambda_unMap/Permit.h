#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include "PermitType.h"

class Permit {

    private:
        std::string _serailNumber;
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

        // Parameterized Constructor.
        Permit(std::string serialNumber, PermitType pType, int permitTimeLeft);

        // Getters
        std::string serailNumber() const { return _serailNumber; }
        PermitType permitType() const { return _permitType; }
        int permitTimeLeft() const { return _permitTimeLeft; }


        // Operator Overloading.
        friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);

        
};


#endif // PERMIT_H
