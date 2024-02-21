#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

enum ctype {
    SUV, HatchBack, Sedan
};

class Car : public Vehicle {
    enum ctype carType;

    public:
        void display();

        // Getter
        
        
        void accept();

        enum ctype getCarType() const { return carType; }
        void setCarType(const enum ctype &carType_) { carType = carType_; }

};

#endif // CAR_H
