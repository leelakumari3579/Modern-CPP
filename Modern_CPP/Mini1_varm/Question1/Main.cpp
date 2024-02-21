#include "Functionalities.h"

int main(int argc, char const *argv[])
{
    CarContainer CarData;
    /* 
    Function 1: creating the Car Container
    */
    CreateObjects(CarData);

    /*
    Function 2: Return Car instance of Nth index of CarContainer
    */
    std::cout<<"----------------------------------------------------------"<<std::endl;
    int index=0;
    std::cout<<"Enter the Position of the Car in the Container"<<std::endl;
    std::cin>>index;
    try
    {
        Car NthCar=FindNthCar(CarData,index);
        std::cout<<NthCar<<std::endl;
    }
    catch(NOCarFoundExeception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(NoCarAvailable& e){
        std::cout << e.what() << '\n';
    }
    std::cout<<"----------------------------------------------------------"<<std::endl;

/*
    Function 3: Search and Display by CarId;
*/
    std::cout<<"----------------------------------------------------------"<<std::endl;
    std::string carId;
    std::cout<<"Enter the CarId of the Car "<<std::endl;
    std::cin>>carId;
    try
    {
        DisplayCarById(CarData,carId);
    }
    catch(NOCarFoundExeception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(NoCarAvailable& e){
        std::cout << e.what() << '\n';
    }
    std::cout<<"----------------------------------------------------------"<<std::endl;
/*
    Function 4:
    Avg Price 
*/
 std::cout<<"----------------------------------------------------------"<<std::endl;
    int ptype;
    std::cout<<"Enter the Permit Type of the Car  0- Tourist 1 -private "<<std::endl;
    std::cin>>ptype;
    try
    {
       std::cout<<"Average price::"<<findAverage_price(CarData,(PermitType)ptype)<<std::endl;
    }
    catch(NOCarFoundExeception& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(NoCarAvailable& e){
        std::cout << e.what() << '\n';
    }
    std::cout<<"----------------------------------------------------------"<<std::endl;
    return 0;
}
