#include "Functionalities.h"

void PerformOperation(FunctionContainer &functionData, DataContainer &data)
{
    if (data.empty())
        throw EmptyContainerException ("container is empty!!");
    for (FunctionType fn : functionData)
    {
        std::cout << fn(data) << "\n";
    }
}

void MakeLambdaFunctions(FunctionContainer &functionData)
{
    // sum of total  odd numbers divisible by 3 from vector
    auto SumOfOddNumbersDivisibleBy3 = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw EmptyContainerException ("container is empty!!");
        int sum = 0;
        for (int val : data)
        {
            if (val % 2 != 0 && val % 3 == 0)
            {
                sum += val;
            }
        }
        if (sum == 0)
            throw  NoMatchingInstanceException("there is no data found which is odd and divisible by 3!!");
        return sum;
    };
    functionData.emplace_back(SumOfOddNumbersDivisibleBy3);

    // Lowest even number from the vector
    auto LowestEvenNumber = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw EmptyContainerException("container is empty!!");
        int minEven = __INT_MAX__;
        for (int val : data)
        {
            if (val % 2 == 0)
            {
                if(minEven >= val)
                {
                    minEven = val;
                }
            }
        }
        if (minEven == __INT_MAX__)
            throw  NoMatchingInstanceException("there is no data found which is even");
        return minEven;
    };
    functionData.emplace_back(LowestEvenNumber);

    // Maximum value from the First three numbers from the vector
    auto MaxFromFirst3Numbers = [](std::vector<int> &data) -> int
    {
        if (data.empty())
            throw EmptyContainerException ("container is empty!!");
        int max = 0;
        int count = 0;
        for (int val : data)
        {
            if (max <= val)
                max = val;
            count++;
            if(count == 3)
                break;
        }
         if (max == 0)
            throw  NoMatchingInstanceException("there is no data found which max of 3 integrs");
        return max;
    };
    functionData.emplace_back(MaxFromFirst3Numbers);
}
