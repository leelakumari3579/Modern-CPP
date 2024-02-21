#include "Functionalities.h"
#include <iostream>
#include "ContainerEmptyException.h"
#include"NoMatchInstanceException.h"

void MakeLambda(std::vector<std::function<std::string(std::vector<std::string>)>> &fns)
{
    std::function<std::string(std::vector<std::string>)> MinimumLength =
        [](const std::vector<std::string>& v)
    {
        std::cout<<"Minimum Length operation occurs"<<std::endl;
        if (v.size() == 0)
        {
            throw ContainerEmptyException("Container empty\n");
        }
        int min = 999999;
        std::string result;
        for (std::string str : v)
        {
            if (min >str.length())
            {
                min=str.length();
                result = str;
            }
        }
        if(result.empty())
        {
            throw NoMatchInstanceException("No Match Instance\n");
        }
        return result;
    };

    std::function<std::string(std::vector<std::string>)> OnlyConsonants =
        [](std::vector<std::string> v)
    {
        std::cout<<"Only consonants operation"<<std::endl;
        if (v.size() == 0)
        {
            throw ContainerEmptyException("Container empty\n");
        }
        std::string result;
        for (std::string str : v)
        {
            int vowelCount = 0;
            
            for (char c : str)
            {
                if (c >= 65 && c <= 90)
                {
                    c = c + 32;
                }
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                {
                    vowelCount++;
                }
            }
            if (vowelCount == 0)
            {
                result = str;
                break;
            }
        }
        if(result.empty())
        {
            throw NoMatchInstanceException("No Match Instance\n");
        }
        return result;
    };

    std::function<std::string(std::vector<std::string>)> SecondPosition =
        [](std::vector<std::string> v)
    {
        std::cout<<"Second Position operation occurs"<<std::endl;
        if (v.size() == 0)
        {
            throw ContainerEmptyException("Container empty\n");
        }
        std::string result;
        int count = 0;
            return v[1];
        
        // for (std::string str : v)
        // {
            // if (count == 1)
            // {
            //     result = str;
            // }
            // count++;
        //}
        // if(result.empty())
        // {
        //     throw NoMatchInstanceException("No Match Instance\n");
        // }
        // return result;
    };
    fns.emplace_back(MinimumLength);
    fns.emplace_back(OnlyConsonants);
    fns.emplace_back(SecondPosition);
}

void PerformOperation(std::vector<std::function<std::string(std::vector<std::string>)>> &fns,
                      std::vector<std::string> &data)
{
    for (std::function<std::string(std::vector<std::string>)> fn : fns)
    {
        std::cout << fn(data) << "\n";
    }
    std::cout << "\n";
}