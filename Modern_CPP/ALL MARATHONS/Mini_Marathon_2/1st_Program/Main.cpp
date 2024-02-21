#include "Functionalities.h"
#include <iostream>
#include"ContainerEmptyException.h"
#include"NoMatchInstanceException.h"
int main()
{
    std::vector<std::function<std::string(std::vector<std::string>)>> fns;
    MakeLambda(fns);
    std::vector<std::string> data{"xyz", "abcd", "efghi"};

    try
    {
        PerformOperation(fns, data);
    }
    catch(ContainerEmptyException& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(NoMatchInstanceException& e)
    {
        std::cout << e.what() << '\n';
    }
    

    

    return 0;
}