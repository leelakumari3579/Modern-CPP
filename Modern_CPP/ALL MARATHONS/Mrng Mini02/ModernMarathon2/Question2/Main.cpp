#include "Functionalities.h"
int main(int argc, char const *argv[])
{
    MotorContainer motors;
    ElectricVehicleContainer Evehicles;

    // function 1;
    try
    {
       createElectricVehicles(motors,Evehicles);
    }
    catch(CreateCheck& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    // function 2;

    try
    {
        std::cout<<" maxTorqueOrmaxPowerBasedOnBatteryCapacity : " <<maxTorqueOrmaxPowerBasedOnBatteryCapacity(Evehicles,"v1")<<std::endl;
      ElectricVehicleContainer res= FilterData(Evehicles,[](float f)->bool {return f>20; });
        std::cout<<" Result Container Size is "<<res.size()<<std::endl;
        calculateBatteryDrain(Evehicles);
        PerformOpeator(Evehicles);
    }
     catch(EmptyContainer& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(IdNotFound& e)
    {
        std::cerr << e.what() << '\n';
    }
    
  /* // fun3;
    try
    {
    }
     catch(EmptyContainer& e)
    {
        std::cerr << e.what() << '\n';
    }
    

    //fun4:  BatteryCapacity >20

     try
    {
    }
     catch(EmptyContainer& e)
    {
        std::cerr << e.what() << '\n';
    }

    //fun5:

      try
    {
        
    }
     catch(EmptyContainer& e)
    {
        std::cerr << e.what() << '\n';
    }


    return 0;*/


}
