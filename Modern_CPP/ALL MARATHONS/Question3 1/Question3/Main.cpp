#include"Functionalites.h"
#include<future>
#include<thread>
#include<mutex>
#include<iostream>


int main()
{
    Container data;

    std::promise<int> pr;

    std::future<int> ft = pr.get_future();

    std::future<void> f1 = std::async(std::launch::async,CreateObjects,std::ref(data));

    f1.get();

    int id = 12;

    pr.set_value(id);


    std::future<void> f2 = std::async(std::launch::async,DisplayAllAttributes,std::ref(data),std::ref(ft));

    std::future<void> f3 = std::async(std::launch::async,AveragePriceOfAllEvCars,std::ref(data));

    std::future<void> f4 = std::async(std::launch::async,SumOfTotalGst,std::ref(data));

    std::future<void> f5 = std::async(std::launch::async,SumOfExchangeAmountOfEv2Wheeler,std::ref(data));

    std::future<std::optional<Container>> f6 = std::async(std::launch::async,ReturnInstancesOfSmartPointer,std::ref(data),3400.0f);
    

    auto result = f6.get();
    //std::cout<<typeid(result).name();
    if(result.has_value()){
        for(auto Instance : result.value()){
            std::cout<<*Instance;

        }
    }

}
