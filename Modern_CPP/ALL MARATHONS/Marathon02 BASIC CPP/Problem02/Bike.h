#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

enum btype {
    Commute, Sports, Offroader
};

class Bike : public Vehicle {
    enum btype bikeType;

    public:
        void display();

        // Getter
        enum btype getBikeType() const { return bikeType; }
        void setBikeType(const enum btype &bikeType_) { bikeType = bikeType_; }
        
        void accept();

};

#endif // BIKE_H
