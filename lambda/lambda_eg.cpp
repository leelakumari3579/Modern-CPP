#include <iostream>
#include <array>
#include <functional>

using FnType = std::function<int(int)>;
using FnContainer = std::array<FnType, 2>;

void Operation(const std::array<int, 5> &data, FnContainer& fns)
{
    for(auto& fn : fns)
    {
        for (int val : data)
            std::cout<<fn(val)<<"\n";
    }
}

// void Operation(const std::array<int, 5> &data, std::function<int(int)> fn)
// {
//     for (int val : data)
//         fn(val);
// }

int main()
{
    int n1 = 100;
    int a = 100;
    // f1 takes one parameter and multiplies it with the n1
    auto f1 = [n1](int num) mutable
    {
        n1 = 99;
        return num * n1;
    };

    auto f2 = [](int num)
    {return num * num;};

    FnContainer fns = {f1, f2};

    Operation(std::array<int, 5>{1, 2, 3, 4, 5}, fns);

    // Operation(std::array<int, 5>{1, 2, 3, 4, 5},
    //                             [](int num)
    //                             { return num * num; });

    return 0;
}

/*
    In capture clause
    [&] means all variables in enclosing function are captured by reference
    [=] means all variables in enclosing function are captured by value
    [&n1] means only n1 variable is caprtured by reference
    [n1] menas only n1 is captured by value
    [n1, &a]:n1 by value and a by reference
*/

// stupid code
//  void Operation(std::array<int, 5> &data, enum class Logic op)
//  {
//      if (op == Logic::SQUARE)
//      {
//          for (int val : data)
//          {
//              std::cout << val * val << "\n";
//          }
//      }
//      else if (op == Logic::CUBE)
//      {
//          for (int val : data)
//          {
//              std::cout << val * val * val << "\n";
//          }
//      }
//  }


