#include "Functionalities.h"
int main(int argc, char const *argv[])
{   
    DataContainer data{1,2};
    std::cout<<"Function 1: Odd multiples of 3 numbers are there in the Conatiner"<<std::endl;
    PerformOperation(data,oddSumDivBy3);

    std::cout<<"Function 2: Lowest even Number in the Conatiner"<<std::endl;
    PerformOperation(data,lowestEven);

    std::cout<<"Function 3:FindMaxAmongThree"<<std::endl;
    PerformOperation(data,FindMaxAmongThree);

    return 0;
}
