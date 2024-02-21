#include "Functionalities.h"

int main()
{
    FunctionContainer functionData;
    std::vector<int> data {3, 9, 15, 18, 24};

    try
    {
        MakeLambdaFunctions(functionData);
    }
    catch (EmptyContainerException &e1)
    {
        std::cout << e1.what() << '\n';
    }

    try
    {
        PerformOperation(functionData, data);
    }
    catch (EmptyContainerException &e1)
    {
        std::cout << e1.what() << '\n';
    }
    catch (NoMatchingInstanceException &e2)
    {
        std::cout << e2.what() << '\n';
    }

}