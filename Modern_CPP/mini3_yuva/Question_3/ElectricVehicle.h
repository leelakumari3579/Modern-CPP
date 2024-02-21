#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include"VehicleType.h"
#include <ostream>

class ElectricVehicle
{
private:
    static int counter;
    int _id;
    VehicleType _type;
    float _price;
    int _seat_count;
    int _engine_horsepower;
public:
    ElectricVehicle()=delete;
    ElectricVehicle(const ElectricVehicle&)=delete;
    ElectricVehicle(ElectricVehicle&&)=delete;
    ElectricVehicle& operator=(ElectricVehicle&&)=delete;
    ElectricVehicle& operator=(const ElectricVehicle&)=delete;
    ~ElectricVehicle()=default;

    ElectricVehicle(VehicleType type,float price,int seatCount,int engineHorsePower);

    virtual float CalculateGst()=0;
    virtual float CalculateExchangeAmount()=0;

    int id() const { return _id; }

    VehicleType type() const { return _type; }

    float price() const { return _price; }

    int seatCount() const { return _seat_count; }

    int engineHorsepower() const { return _engine_horsepower; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);
    
};

#endif // ELECTRICVEHICLE_H
