#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

#include"ElectricVehicleType.h"
#include <ostream>
class ElectricVehicle  // PURE ABSTRACT CLASS
{
private:
    inline static int _counter=999;
    const int _id;
    ElectricVehicleType _type;
    float _price;
    int _seat_count;
    int _engine_horsepower;

public:

    ElectricVehicle(ElectricVehicleType type,float price,int seat_count,int engine_horsepower);

    ElectricVehicle() =delete;
    ElectricVehicle(const ElectricVehicle&)=delete;
    ElectricVehicle(ElectricVehicle&&)=delete;
    ElectricVehicle& operator=(const ElectricVehicle&)=delete;
    ElectricVehicle& operator=(ElectricVehicle&&)=delete;
    virtual ~ElectricVehicle()=default;

    int id() const { return _id; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    int seatCount() const { return _seat_count; }
    void setSeatCount(int seat_count) { _seat_count = seat_count; }

    int engineHorsepower() const { return _engine_horsepower; }
    void setEngineHorsepower(int engine_horsepower) { _engine_horsepower = engine_horsepower; }

    virtual float CalculateGst()=0;

    virtual float CalculateExchangeAmount()=0;

    ElectricVehicleType type() const { return _type; }
    void setType(const ElectricVehicleType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const ElectricVehicle &rhs);

   
};

#endif // ELECTRICVEHICLE_H
