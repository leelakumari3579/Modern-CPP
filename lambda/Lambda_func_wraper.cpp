/*
create a function that accepts a container of functions and container of numbers
apply every function on the whole container at once
fns = [f1|f2|f3]  data = [10|20|30]
for(fn : fns)
{
    f1(data);
}
using FnType = std::function(int(std::vector<int>));
std::vector<FnType> fns;
*/
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

using FnType = std::function<int(std::vector<int>& data)>;
using FnContainer = std::vector<FnType>;
using DataContainer = std::vector<int>;

void Operation(FnContainer& fns, DataContainer& data)
{
    for(FnType fn : fns)
    {
        fn(data);
    }
}

int main()
{
    //find the first number in vector
    auto f1 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        return data.front();
    };

    //find last number
    auto f2 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        return data.back();
    };

    //find total
    auto f3 = [](std::vector<int>& data)->int{
        if(data.empty())
            throw std::runtime_error("data is empty!!");
        int total = 0.0f;
        for(int val : data)
            total += val;
        return total;
    };

    std::vector<FnType> fns {f1,f2,f3}; ///f1,f2,f3 are not functions...they are objects
}