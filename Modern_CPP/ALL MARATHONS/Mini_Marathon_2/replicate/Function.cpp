#include "Function.h"
#include<array>

void CreateObjects(std::vector<std::shared_ptr<Car>>& Carvector){
    Carvector.emplace_back(std::make_shared<ICEngineCar>(120000.0f,"Tata",CarType::PRIVATE_CAR,4,80.0f,FuelType::DIESEL));
    Carvector.emplace_back(std::make_shared<ICEngineCar>(20000.0f,"Maruthi",CarType::TOURIST_PERMIT_CAR,6,100.0f,FuelType::CNG));
    Carvector.emplace_back(std::make_shared<EvCar>(1000000.0f,"Odi",CarType::PRIVATE_CAR,4,10000));
}
 std::function<float(std::vector<std::shared_ptr<Car>>,CarType)> CarTypeAverageInsuranceCost=[](std::vector<std::shared_ptr<Car>> vectorCar,CarType ct){
    float sum=0.0f;
    int count=0;
    for(std::shared_ptr<Car> car: vectorCar){
        if(car->cType()==ct){
            sum+=car->CalculateInsuranceCost();
            count++;
        }
    };
    return sum/count;
};

 std::function<std::array<int,2>(std::vector<std::shared_ptr<Car>>)> CountChildInstancesWithConditions=
[]( const std::vector<std::shared_ptr<Car>>& vectorCar){
    int countEv=0;
    int countICE=0;
    std::array<int,2> output;
    for(auto car:vectorCar){
        std::shared_ptr<EvCar> ev =std::dynamic_pointer_cast<EvCar>(car);
        std::shared_ptr<ICEngineCar>ice=std::dynamic_pointer_cast<ICEngineCar>(car);
        if(ev!=nullptr && ev->CalculateInsuranceCost()>2000.0f){
            countICE++;
        }
        if(ice!=nullptr && ice->CalculateInsuranceCost()>2000.0f){
            countICE++;
        }
    }
        output[0]=countEv;
        output[1]=countICE;

    
    return output;

};

 
