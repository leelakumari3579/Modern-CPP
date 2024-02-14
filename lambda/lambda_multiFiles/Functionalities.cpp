#include "Functionalities.h"

void Operation(FnContainer& fns, DataContainer& data)
{
    for(FnType fn : fns)
    {
       std::cout<<fn(data)<<"\n";
    }
}

void MakeLambda(FnContainer& fns)
{
    //find the first number in vector
    auto f1 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        return data.front();
    };
    fns.emplace_back(f1);
    

    //find last number
    auto f2 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        return data.back();
    };
    fns.emplace_back(f2);


    //find total
    auto f3 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        int total = 0.0f;
        for(int val : data)
            total += val;
        return total;
    };
    fns.emplace_back(f3);

    // fns.emplace_back(f1);
    // fns.emplace_back(f2);
    // fns.emplace_back(f3);
}
    
