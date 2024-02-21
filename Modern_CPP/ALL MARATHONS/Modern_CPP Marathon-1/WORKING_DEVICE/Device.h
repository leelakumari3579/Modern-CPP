#ifndef DEVICE_H
#define DEVICE_H

#include<iostream>


//using WorkingDevicePointer=std::shared_ptr<WorkingDevice>;
class Device 
{
    private:
       std::string _id;
       std::string _name;
       float _price;
      // WorkingDevicePointer _workingDevice;

    public:
       //Constructors
        Device()=delete;
        Device(const Device&)=delete;
        Device(const Device&&)=delete;
        Device& operator=(const Device&)=delete;
        Device& operator=(const Device&&)=delete;
        ~Device()=default;

        //member function
        virtual void FindDiscountPrice() =0;

        //parameterized Constructor
        Device(std::string id,std::string name,float price);
        
        //getter and setter
        std::string id() const { return _id; }

        std::string name() const { return _name; }

        float price() const { return _price; }
        void setPrice(float price) { _price = price; }

        //WorkingDevicePointer workingDevice() const { return _workingDevice; }

        friend std::ostream &operator<<(std::ostream &os, const Device &rhs);

        
        
};

#endif // DEVICE_H
