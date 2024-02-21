#include "Functionalities.h"

void createElectricVehicles(MotorContainer &motors, ElectricVehicleContainer &Evehicles)
{   
    // initialising Motors; stack memory
    motors.emplace_back(Motor(23,234,350));
    motors.emplace_back(Motor(34,322,323));
    motors.emplace_back(Motor(43,234,450));
    motors.emplace_back(Motor(34,229,459));
    //initalising Evehicles;  Heap Memory
    
   Evehicles.emplace_back(std::make_shared<ElectricVehicle>("v1","model1",BatteryType::LITHIUM_ION,78.0f,std::ref(motors[0])));
   Evehicles.emplace_back(std::make_shared<ElectricVehicle>("v2","model2",BatteryType::LITHIUM_ION,68.0f,std::ref(motors[1])));
   Evehicles.emplace_back(std::make_shared<ElectricVehicle>("v3","model3",BatteryType::NICKEL_METAL_HYDRIDE,58.0f,std::ref(motors[2])));
   Evehicles.emplace_back(std::make_shared<ElectricVehicle>("v4","model4",BatteryType::NICKEL_METAL_HYDRIDE,48.0f,std::ref(motors[3])));

  //checking valid inputs / not;

  for(ElectricVehiclePointer& eptr:Evehicles){
    if(eptr->batteryCapacity()<0 || eptr->motor().get().maxPower()<0 || eptr->motor().get().maxTorque()<0 || eptr->motor().get().time0To_100()<0){
        throw CreateCheck("The Attributes have negative values");
    }
  }
}

float maxTorqueOrmaxPowerBasedOnBatteryCapacity(ElectricVehicleContainer &Evehicles, std::string id)
{
    if(Evehicles.size()==0){
      throw EmptyContainer("It is an Empty Container");
    }
    for(ElectricVehiclePointer& eptr:Evehicles){
      if(eptr->id()==id){
        if(eptr->batteryCapacity()>30.3){
          return eptr->motor().get().maxTorque();
        }else{
          return eptr->motor().get().maxPower();
        }
      }
  }
  throw IdNotFound("No Id Found");

}

void calculateBatteryDrain(ElectricVehicleContainer &Evehicles)
{     
   if(Evehicles.size()==0){
      throw EmptyContainer("It is an Empty Container");
    }
  std::cout<<"calculateBatteryDrain"<<std::endl;
   for(ElectricVehiclePointer& eptr:Evehicles){
      std::cout<<eptr->EvaulateChargingRate()<<std::endl;
  }
}


ElectricVehicleContainer FilterData(ElectricVehicleContainer &Evehicles, FunType fn)
{
    if(Evehicles.size()==0){
      throw EmptyContainer("It is an Empty Container");
    }
    ElectricVehicleContainer res;
     for(ElectricVehiclePointer& eptr:Evehicles){
      if(fn(eptr->batteryCapacity())){
        res.push_back(eptr);
      }
  }
  if(res.empty()){
    throw EmptyContainer("Result is an Empty Container");
  }
    return res;
}

void PerformOpeator(ElectricVehicleContainer& Evehicles){
  std::cout<<"Perform Operation +" <<std::endl;
  std::cout<<*Evehicles.front()+*Evehicles.back()<<std::endl;
}
