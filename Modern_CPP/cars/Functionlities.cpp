#include "Functionlities.h"
#include<stdexcept>

void CreateObjects(container &data)
{
    // Car* c1 = new Car("v101ef",780000.0f,VehicleType::SEDAN);
    // data.push_back(c1);
    data.push_back(
        std::make_shared<Car>(
            "v101ef",
            780000.0f,
            VehicleType::SEDAN)
    );

    data.push_back(
        std::make_shared<Car>(
            "v202ab",
            890000.0f,
            VehicleType::SUV)
    );
}

float AveragePrice(container &data)
{
    float total = 0.0f;
    /*
        for each pointer called "ptr" in data,
        access price getter using "ptr" and add it to "total"
    */
    for( Pointer& ptr : data)
    {
        total += ptr->price();
    }
    return total/data.size();
}

float FindPriceById(container &data, std::string id)
{
    for(Pointer& ptr : data)
    {
        if(ptr->id() == id)
        {
            return ptr->price();
        }
    }
    throw std::runtime_error("ID NOT FOUND\n");
}

//data[0] ->sp1 ->get_internal_pointer ->price()

/*
data[0].get() ->price();
data[0] ->price();
*/