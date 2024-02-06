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
        std::cout << e1.what() << '\n';
    }
    catch (IdNotFoundException &e2)
    {
        std::cout << e2.what() << '\n';
    }


    try
    {
        std::vector<Car> result = FindAbove80TorqueCars(carData);
        std::cout << "details of cars above 80 torque are: " << std::endl;
        for (Car &c : result)
        {
            std::cout << c << "\n";
        }
    }
    catch (EmptyContainerException &ex1)
    {
        std::cout << ex1.what() << '\n';
    }
    catch (NoMatchingInstanceException &ex2)
    {
        std::cout << ex2.what() << '\n';
    }

//     std::vector<Engine> res = FindEngineDetilsByCarType(carData,CarType::SEDAN);
//     for (Engine& e : res)
//     {
//         std::cout<<"Engine derails "<< e << "\n";
//     }

    float res2 = AverageHoursepower(carData);
    std::cout<<"avg hoursepower: "<<res2<<"\n";

    std::string res3 = FindLowPriceByCarId(carData);
    std::cout<<"low price carId is: "<<res3<<std::endl;

    float res4 = TwoCarInstancesCombinedPrice(carData[0],carData[1]);
    std::cout<<"combined price of two cars : "<<res4<<"\n";
}