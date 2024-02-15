#include "DataHandler.h"
#include <iostream>
#include <future>
#include <thread>
#include <optional>

int main()
{
    std::array<int, 5> d1{1, 2, 3, 4, 5};
    std::array<int, 5> d2{6, 7, 8, 9, 0};
    DataHandler data1(d1);
    DataHandler data2(d2);
    auto lambdaFn = ([](int num)
                     { if(num % 3 == 0)
                     return num; },
                     data1);

    try
    {        
        // std::future<std::function<int(std::array<int, 5>)>> result1 =
        //     std::async(std::launch::async, &DataHandler::FilterData,&data1,lambdaFn);
        // std::cout<<"value which is divisible by 3: "<<result1.get();
    }
    catch (EmptyDataException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (NoMatchingInstanceException &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::future<int> result2 = std::async(std::launch::async, &DataHandler::FindNthValue, &data1, 2);
        // int result2 = data1.FindNthValue(2);
        std::cout << "The value present in Nth position is: " << result2.get() << "\n";
    }
    catch (EmptyDataException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (NvalueNotFoundException &e)
    {
        std::cerr << e.what() << '\n';
    }

    try
    {
        std::future<int> result3 = std::async(std::launch::async, &DataHandler::SumOfOdd, &data1);
        // int result3 = data1.SumOfOdd();
        std::cout << "Sum of Odd numbers: " << result3.get() << "\n";
    }
    catch (EmptyDataException &e)
    {
        std::cerr << e.what() << '\n';
    }
    catch (NoMatchingInstanceException &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::thread th(&data2,&data1);
    auto result = data1+data2;
    std::cout<<"sum of two instances: "<<result;
    th.join();
}
