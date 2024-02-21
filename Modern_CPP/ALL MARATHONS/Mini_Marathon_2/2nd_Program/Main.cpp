#include <iostream>
#include "Functionalities.h"
#include "ContainerEmptyException.h"
#include "NoMatchInstanceException.h"

int main()
{
    std::vector<std::shared_ptr<Flight>> vectorFlight;
    std::vector<AirPlane> vectorAirPlane;
    CreateObjects(vectorFlight, vectorAirPlane);

    std::cout << "MatchByFlightOperatorTypeInstances"
              << "\n";
    try
    {
        for (AirPlane airPlane : MatchByFlightOperatorType(vectorFlight, FlightOperatorType::DOMESTIC))
        {
            std::cout << airPlane << std::endl;
        }
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
    //--------------------------------------------------------------------
    std::cout << "LowestAirPlaneSeatCount"
              << "\n";
    try
    {
        if (LowestAirPlaneSeatCount(vectorFlight) == AirPlaneType::NEO)
        {
            std::cout << "Air plane type is NEO"
                      << "\n";
        }
        else if (LowestAirPlaneSeatCount(vectorFlight) == AirPlaneType::JUMBO)
        {
            std::cout << "Air plane type is JUMBO"
                      << "\n";
        }
        else if (LowestAirPlaneSeatCount(vectorFlight) == AirPlaneType::CRUISELINER)
        {
            std::cout << "Air plane type is CRUISELINER"
                      << "\n";
        }
    }
    catch (ContainerEmptyException &e)
    {
        std::cout << e.what() << '\n';
    }
    //----------------------------------------------------------
    std::cout<<"\n";
    std::cout << "ThresholdAirPlaneCount"
              << "\n";
    try
    {
        for (AirPlane airPlane : ThresholdAirPlaneCount(vectorAirPlane, 50))
        {
            std::cout << airPlane << std::endl;
        }
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
    //------------------------------------------------------------------

    std::cout << "TotalAirPlaneSeatCount"
              << "\n";
    try
    {
        std::cout << TotalAirPlaneSeatCount(vectorAirPlane) << std::endl;
    }
    catch (ContainerEmptyException &e)
    {
        std::cout << e.what() << '\n';
    }
    
    std::cout << "\n";
    //------------------------------------------------------------
    std::cout<<"\n";
    std::cout << "Filter Data"
              << "\n";
    try
    {
        for (std::shared_ptr<Flight>& flightPointer:FilterData(Utility,vectorFlight))
        {
            std::cout << *flightPointer << std::endl;
        }
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