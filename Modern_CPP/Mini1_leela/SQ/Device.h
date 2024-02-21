#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>

class Device
{
private:
    const std::string _id;
    std::string _name;
    float _price;
public:
    Device() = default;                       //default constructor
    Device(const Device &) = delete;             // deleted copy constructor
    ~Device() = default;                      // defaulted destructor
    Device &operator=(const Device &) = delete;  // deleted assignment operator overloading
    Device &operator=(const Device &&) = delete; // new concept! (move assignment)
    Device(const Device &&) = delete;  

    Device(std::string id, std::string name, float price);
    virtual void FunctionDiscountPrice() = 0;

    std::string id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
    
};



#endif // DEVICE_H
