#include"Function.h"
#include<iostream>

int main(){
    std::vector<std::shared_ptr<Car>> carVector;
    CreateObjects(carVector);
   std::cout<< CarTypeAverageInsuranceCost(carVector,CarType::PRIVATE_CAR);
   std::array<int,2>result= CountChildInstancesWithConditions(carVector);
  for(auto ele:result){
    std::cout<<ele<<" ";
  }
}