#include "Functionalities.h"
#include <iostream>

int main()
{
    FnContainer fns;
    std::vector<int> data {10,32,89,32};
    MakeLambda(fns);
    Operation(fns, data);

    /*
    create a new partial function that attaches dummy data
    to second parameter of operation
    */
    std::vector<int> dummyData {1,2,3};

    auto bindedOperation = std::bind(Operation, std::placeholders::_1, std::ref(dummyData));
    bindedOperation(fns);
}