#include <iostream>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "IdNotFoundExecption.h"
#include "NoMatchingInstanceException.h"

int main()
{
    CarPointerContainer carData;
    EngineContainer engineData; 

    CreateObjects(carData, engineData);

    try
    {
        // FindHoursepowerByCarId(carData, "000");
        int ans = FindHoursepowerByCarId(carData, "000");
        std::cout << "hoursepower for a given id is: " << ans << std::endl;
    }
    catch (EmptyContainerException &e1)
    {
        std::cout << e1.what() << std::endl;
    }
    catch (IdNotFoundException &e2)
    {
        std::cout << e2.what() <<std::endl;
    }


    try
    {
        std::optional<std::vector<Car>> result = FindAbove80TorqueCars(carData);
        std::cout << "details of cars above 80 torque are: " << std::endl;
        if(result.has_value()) //if result has value
        {
            for (Car &c : result.value()) //result values to Car c
            {
                std::cout << c << std::endl;
            }   
        }
    }
    catch (EmptyContainerException &ex1)
    {
        std::cout << ex1.what() << std::endl;
    }
    catch (NoMatchingInstanceException &ex2)
    {
        std::cout << ex2.what() << std::endl;
    }

//     std::vector<Engine> res = FindEngineDetilsByCarType(carData,CarType::SEDAN);
//     for (Engine& e : res)
//     {
//         std::cout<<"Engine derails "<< e << std::endl;;
//     }

    float res2 = AverageHoursepower(carData);
    std::cout<<"avg hoursepower: "<<res2<<std::endl;

    std::string res3 = FindLowPriceByCarId(carData);
    std::cout<<"low price carId is: "<<res3<<std::endl;

    float res4 = TwoCarInstancesCombinedPrice(carData[0],carData[1]);
    std::cout<<"combined price of two cars : "<<res4<<std::endl;
}