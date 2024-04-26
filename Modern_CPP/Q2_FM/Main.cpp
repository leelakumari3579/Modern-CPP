#include<iostream>
#include"Functionalities.h"

int main()
{
    VehicleContainer data;
    CreateObjects(data);

    try
    {
        std::optional<std::list<VehiclePointer>> result=FindLastNinstances(data,3);
        if(result.has_value())
        {
            for(auto ptr:result.value())
            {
                std::cout<<*ptr<<"\n";
            }
        }
        else
        {
            std::cout<<"N is out of range"<<"\n";
        }
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
    try
    {
        std::list<std::string> id={"S101","S102","S103"};
        std::unordered_map<std::string,std::string> result=FindPairByVehicleId(data,id);
        for(auto itr:result)
        {
            std::cout<<"VehicleId:"<<itr.first<<" "<<"ServiceId:"<<itr.second<<"\n";
        }
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
    try
    {
        std::unordered_map<std::string,ServicePointer> result=FindMaximumServiceChargeInstance(data);
        for(auto itr:result)
        {
            std::cout<<"VehicleId:"<<itr.first<<" "<<"ServiceRecord:"<<*itr.second<<"\n";
        }
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
    try
    {
        std::cout<<"Average charge:"<<AverageChargesOfRegularType(data);
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
    try
    {
        std::optional<std::string> id=FindVehicleIdByServiceId(data,"S102");
        if(id.has_value())
        {
            std::cout<<"Vehicle id:"<<id.value()<<"\n";
        }
        else
        {
            std::cout<<"no instance found with given service id"<<"\n";
        }
    }
    catch(EmptyContainerException& e)
    {
        std::cout<<e.what()<<"\n";
    }

    return 0;
}