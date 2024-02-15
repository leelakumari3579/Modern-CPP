#include"Functionalities.h"
#include<iostream>

void CreateObjects(Container& data,ContainerMotor& dataMotor)
{
    dataMotor.emplace_back(Motor(55.0f,200.8f,50));
    dataMotor.emplace_back(Motor(56.0f,310.0f,52));
    dataMotor.emplace_back(Motor(57.0f,120.0f,54));
    dataMotor.emplace_back(Motor(58.0f,340.0f,56));

    ElectricVehiclePointer sp1 = std::make_shared<ElectricVehicle>("123","Ev1",BatteryType::LITHIUM_ION,26.0f,dataMotor[0]);
    ElectricVehiclePointer sp2 = std::make_shared<ElectricVehicle>("456","Ev2",BatteryType::NICKEL_METAL_HYDRIDE,57.0f,dataMotor[1]);
    ElectricVehiclePointer sp3 = std::make_shared<ElectricVehicle>("789","Ev3",BatteryType::LITHIUM_ION,58.0f,dataMotor[2]);
    ElectricVehiclePointer sp4 = std::make_shared<ElectricVehicle>("123","Ev4",BatteryType::NICKEL_METAL_HYDRIDE,59.0f,dataMotor[3]);


    data.emplace_back(sp1);
    data.emplace_back(sp2);
    data.emplace_back(sp3);
    data.emplace_back(sp4);

}


std::variant<float,unsigned int> AcceptsIdReturnsTorqueOrPower(Container& data,std::string id)
{   
       std::variant<float,unsigned int> res;
        if(data.empty())
        {
            throw EmptyContainerException("Data is Empty!!");
        }

        for(ElectricVehiclePointer& ev : data)
        {
            if(ev->id()==id)
            {

                if(ev->batteryCapacity()>30.3)
                {
                    res= ev->motor().get().maxTorque();
                }
                else if(ev->batteryCapacity()<30.3)
                {
                    res= ev->motor().get().maxPower();
                }
                
               break;
            }
        
            // If exactly 30.3 Returns Exception
        if(ev->batteryCapacity()==30.3)
        {
            throw ValidDataNotFoundException("battery capacity is exactly 30.3 No Valid data");
        }

        }

    return res;
    
}

void DisplaysBatteryDrain(Container& data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data is Empty!!!");
    }

    for(ElectricVehiclePointer& ev : data )
    {   
        float batteryDrain=0.0f;
        if(ev->batteryType()==BatteryType::LITHIUM_ION)
        {
             batteryDrain = 0.1f*ev->batteryCapacity();

        }
        if(ev->batteryType()==BatteryType::NICKEL_METAL_HYDRIDE)
        {
            int torque = ev->motor().get().maxTorque();
            int power  = ev->motor().get().maxPower();

            batteryDrain = ((0.1f*torque)+(0.2f*power));

        }
        std::cout<<"the Battery Drain of Ev of Id "<<ev->id()<<"is "<<batteryDrain<<std::endl;
    }

}



Container FilterData(Container& data,std::function<int(ElectricVehiclePointer& evptr)> fn)
{

      Container TempData;

        if(data.empty())
        {
            throw EmptyContainerException("Data is Empty!!!");
        }

  

    for(ElectricVehiclePointer& evptr1 : data )
    {

            if(fn(evptr1))
            {
                TempData.push_back(evptr1);
            }

    }

    if(TempData.empty())  // No Instance Not Found
    {
        throw NoInstanceFoundException("No Instance Found Exception!!!");
    }

    return TempData;

}

void PerformOperator(Container &data)
{
    std::cout<<"Operation "<<std::endl;
    std::cout<<*data[0]+*data[data.size()-1]<<std::endl;
}
