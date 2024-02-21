#ifndef CAR_H
#define CAR_H

#include <string>
#include <ostream>
#include "PermitType.h"
#include "ChasisType.h"
class Car
{
private:
    const std::string _id;
    float _price;
    const ChasisType _chasisType;
   const  PermitType _permitType;
public:


/* Car */
    Car()=delete;
    Car(const Car&)=default;
    Car(Car&&)=default;
    Car& operator=(const Car&)=delete;
    Car& operator=(Car&&)=delete;
    ~Car()=default;
/*Parametric Constructor*/
    Car(std::string id,float price,ChasisType chasisType,PermitType permitType);
/* Getter ans Setters */
    std::string id() const { return _id; }
    float price() const { return _price; }
    void setPrice(float price) { _price = price; }
    ChasisType chasisType() const { return _chasisType; }
    PermitType permitType() const { return _permitType; }
/* Member functions */
    float calculateCarDiscount();

/*operator overload functions*/
    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
    float operator+(const Car& car);


};

#endif // CAR_H
