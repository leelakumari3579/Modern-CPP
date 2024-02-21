#include "Functionalities.h"
#include "NegativeValueException.h"
#include "LimitValueException.h"
#include "ContainerEmptyException.h"
#include "NoMatchInstanceException.h"

int main()
{

    std::vector<std::shared_ptr<Car>> vectorCar;
    try
    {
        CreateObjects(vectorCar);
    }
    catch (NegativeValueException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (LimitValueException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "\n";
    //-------------------------------------------------------
    std::cout << "CarTypeAverageInsuranceCost"
              << "\n";
    try
    {
        std::cout << CarTypeAverageInsuranceCost(vectorCar, CarType::PRIVATE_CAR);
    }
    catch (ContainerEmptyException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (NoMatchInstanceException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "\n";
    //--------------------------------------------------------
    std::cout << "CountChildInstancesWithConditions"
              << "\n";
    try
    {
        for (int res : CountChildInstancesWithConditions(vectorCar))
        {
            std::cout << res << " ";
        }
        std::cout << "\n";
    }
    catch (ContainerEmptyException &e)
    {
        std::cout << e.what() << '\n';
    }

    std::cout << "\n";
    //------------------------------------------------------------
    std::cout << "CarTypeAverageInsuranceCost using binding"
              << "\n";
    try
    {
        auto bindAverageInsuranceCost=std::bind(CarTypeAverageInsuranceCost,std::placeholders::_1,std::placeholders::_2);
        std::cout<<bindAverageInsuranceCost(vectorCar,CarType::PRIVATE_CAR,"hiii");
    }
    catch (ContainerEmptyException &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (NoMatchInstanceException &e)
    {
        std::cout << e.what() << '\n';
    }
    std::cout << "\n";



    return 0;
}