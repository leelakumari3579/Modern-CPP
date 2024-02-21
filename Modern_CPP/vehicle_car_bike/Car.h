#ifndef CAR_H
#define CAR_H
#include <string>
#include "VehicleType.h"
#include "Vehicle.h"
#include "CarType.h"

/*
    A Car can not be copied or moved
    default instantiation should not be allowed
    This class inherits (extends) a vehile type
    As such, it implements all base class abstract functions
*/

class Car : public Vehicle
{
private:
    CarType _carType;
public:
    Car() = delete;
    Car(const Car&) = delete;
    Car(Car&&) = delete;
    Car& operator=(const Car&) = delete;
    Car& operator=(Car&&) = delete;
    ~Car() = default;
    
    Car(CarType ctype, std::string id);
    Car(CarType ctype, std::string id, VehicleType vtype);
    Car(CarType ctype, std::string id, float price, VehicleType vtype);

    CarType carType() const { return _carType; }

    void BookServiceAppointment() override;
    float CalculateRegistrationTax() override;
};

#endif // CAR_H