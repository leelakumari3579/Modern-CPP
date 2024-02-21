#include "Functionalities.h"

int main()
{
    DataContainer data;
    createObjects(data);

    try
    {
        std::cout << "total was: " << CalculateTotalRegistrationTax(data);
    }
    catch (std::runtime_error &ex)
    {
        std::cout << ex.what() << "\n";
    }

    // std::dynamic_pointer_cast<Car>(data[0])->carType();
}