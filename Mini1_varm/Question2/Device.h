#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
class Device
{
private:
    const std::string _id;
    const std::string _name;
    float _price;
public:
    Device()=delete;
    Device(const Device&)=delete;
    Device(Device&&)=delete;
    Device& operator=(const Device&)=delete;
    Device& operator=(Device&&)=delete;
    ~Device()=default;

/* parametric*/
    Device( const std::string id,std::string name,float price);

    virtual void FindDiscountPrice()=0;

    std::string id() const { return _id; }
    std::string name() const { return _name; }
    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);

};

#endif // DEVICE_H
