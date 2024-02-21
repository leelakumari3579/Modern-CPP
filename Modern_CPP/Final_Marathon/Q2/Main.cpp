#include "Functionalities.h"
#include <iostream>

int main()
{
    VehicleContainer data;
    CreateObjects(data);
    try
    {
        auto result = ReturnListOfLastNinstances(data, 3);
        for (VehiclePointer &ptr : result)
            std::cout << *ptr << "\n";

        std::vector<std::string> strData{"102l", "103l", "104l"};
        auto result2 = ReturnDictionary(data, strData);
        for (auto &&ptr : result2)
            std::cout << "VehicleId as key: "<<ptr.first<<" ServiceId as value: "<<ptr.second<< "\n";

        auto result3 = ReturnDictionaryOfLatestRecord(data);
        for (auto &&ptr : result3)
            std::cout << "VechileId as key: "<<ptr.first<<"Latest sevice record as value: "<<ptr.second<< "\n";

        std::cout<<"Average of service charges of REGULAR: "<<AvegrageChargesofServiceRecord(data)<<"\n";

        std::cout<<"vehickeId based on ServiceId: "<<ReturnVehicleIdByServiceId(data,"201l")<<"\n";
    }
    catch (EmptyContainerException &ex1)
    {
        std::cout << ex1.what() << '\n';
    }
    catch (NoMatchingInstanceException &ex2)
    {
        std::cout << ex2.what() << '\n';
    }
}