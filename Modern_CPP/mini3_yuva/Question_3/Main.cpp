#include"Functionalities.h"
#include<future>
#include<iostream>
int main()
{
    EVContainer data;
    CreateObjects(data);

    std::promise<int> pr;
    std::future<int> ft=pr.get_future();
    std::future<void> result=std::async(std::launch::async,DisplayAttributesOfGivenId,std::ref(data),std::ref(ft));
    int idVal;
    std::cin>>idVal;
    pr.set_value(idVal);
    result.get();
    std::optional<float> average=AveragePriceOfAllEvCars(data);
    if(average.has_value())
    {
        std::cout<<"Average of all Ev cars="<<average.value()<<"\n";
    }
    else
    {
        std::cout<<"No EV car found!\n";
    }

    std::optional<EVContainer> instances=InstancesOfPriceAboveThresholdValue(data,30000);
    if(instances.has_value())
    {
        for(EVehiclePointer& ptr:instances.value())
        {
            std::cout<<*ptr<<"\n";
        }
    }
    
     std::cout<<"Total GST Amount="<<CalculetSumOfGST(data)<<"\n";
     std::cout<<"Total Exchange amont for EV2 vehicle="<<CalculateTotalExchangeAmount(data)<<"\n";
}
