#include"DataHandler.hpp"
#include<iostream>
#include<future>
#include<thread>
#include"DataEmptyException.hpp"
#include"InvalidNvalueException.hpp"
#include"Functionalities.hpp"

int main()
{
    std::array<int,5> data{1,2,3,4,5};
    DataHandler obj1(data);
    std::array<int,5> data1{1,2,3,4,5};    
    DataHandler obj2(data);
    auto fn=[](int& num)->bool{return num%3==0;};
    try
    {
        std::future<void> filterData=std::async(std::launch::async,&DataHandler::FilterData,&obj1,std::ref(fn));
        filterData.get();
        std::future<int> nThValue=std::async(std::launch::async,&DataHandler::FindNthValue,&obj1,2);
        std::cout<<"The value at N th position is "<<nThValue.get()<<"\n";
        std::future<std::optional<int>> sumOfOdd=std::async(std::launch::async,&DataHandler::SumOfOdd,&obj1,std::ref(fn));
        if(std::optional<int> result=sumOfOdd.get();result.has_value())
        {
            std::cout<<"Sum of all odd numbers = "<<result.value()<<"\n";
        }
        else
        {
            std::cout<<"No Odd numbers in the data\n";
        }
        std::thread th1(SumOfObjects,std::ref(obj1),std::ref(obj2));
        if(th1.joinable())
        {
            th1.join();
        }
    }
    catch(DataEmptyException& e)
    {
        std::cerr << e.what() << '\n';
    }
    catch(InvalidNvalueException& e)
    {
        std::cerr << e.what() << '\n';
    }
  
}