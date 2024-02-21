#include"Functionalities.h"
#include"ContainerEmptyException.h"
#include"NoMatchInstanceException.h"

void CreateObjects(std::vector<std::shared_ptr<Flight>>& vectorFlight,std::vector<AirPlane>& vectorAirPlane)
{
    vectorAirPlane.emplace_back(AirPlane("TATA",AirPlaneType::NEO,30));
    vectorAirPlane.emplace_back(AirPlane("TCS",AirPlaneType::JUMBO,40));
    vectorAirPlane.emplace_back(AirPlane("SWAG",AirPlaneType::CRUISELINER,50));

    auto itr=vectorAirPlane.begin();

    vectorFlight.emplace_back(std::make_shared<Flight>
    ("Birla",FlightOperatorType::DOMESTIC,vectorAirPlane[0])
    );
    vectorFlight.emplace_back(std::make_shared<Flight>
    ("KPIT",FlightOperatorType::INTERNATIONAL,vectorAirPlane[1])
    );
    vectorFlight.emplace_back(std::make_shared<Flight>
    ("GOOGLE",FlightOperatorType::INTERNATIONAL,vectorAirPlane[2])
    );
}

std::vector<std::shared_ptr<Flight>> FilterData(std::function<bool(AirPlaneType airplanetype)> &fn,
 std::vector<std::shared_ptr<Flight>> &vectorFlight)
{
    if (vectorFlight.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    std::vector<std::shared_ptr<Flight>> result;
    for(std::shared_ptr<Flight> &flight:vectorFlight)
    {
        if(Utility(flight->airPlane().get().airPlaneType()))
        {
            result.emplace_back(flight);
        }
    }
    if(result.empty())
    {
        throw NoMatchInstanceException("Result is Empty\n");
    }

    
    return result;
}

std::function<std::vector<AirPlane>(std::vector<std::shared_ptr<Flight>>,FlightOperatorType)> MatchByFlightOperatorType = [](
const std::vector<std::shared_ptr<Flight>> &vectorFlight,FlightOperatorType fo)
{
    if (vectorFlight.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    std::vector<AirPlane> result;
    for (std::shared_ptr<Flight> flight : vectorFlight)
    {

        if (flight->flightOperatorType()==fo)
        {
            result.push_back(flight->airPlane());
        }
    }
    if (result.empty())
    {
        throw NoMatchInstanceException("No Match Instance Found\n");
    }
    return result;
};

std::function<AirPlaneType(std::vector<std::shared_ptr<Flight>>)> LowestAirPlaneSeatCount = [](
const std::vector<std::shared_ptr<Flight>> &vectorFlight)
{
    if (vectorFlight.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    AirPlaneType result;
    int min=999999;
    for (std::shared_ptr<Flight> flight : vectorFlight)
    {
        if(min>flight->airPlane().get().airPlaneSeatCount())
        {
            min=flight->airPlane().get().airPlaneSeatCount();
            result=flight->airPlane().get().airPlaneType();
        }
        
    }
    
    return result;

};

std::function<std::vector<AirPlane>(std::vector<AirPlane>,int)> ThresholdAirPlaneCount=
[](std::vector<AirPlane> vectorAirPlane,int threshold)
{
    if (vectorAirPlane.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    std::vector<AirPlane> result;
    for (AirPlane airPlane: vectorAirPlane)
    {

        if (airPlane.airPlaneSeatCount()>=threshold)
        {
            result.push_back(airPlane);
        }
    }
    if (result.empty())
    {
        throw NoMatchInstanceException("No Match Instance Found\n");
    }
    return result;
};

std::function<int(std::vector<AirPlane>)> TotalAirPlaneSeatCount=
[](std::vector<AirPlane> vectorAirPlane)
{
    if (vectorAirPlane.empty())
    {
        throw ContainerEmptyException("Vector is empty\n");
    }
    int total=0;
    for (AirPlane airPlane: vectorAirPlane)
    {

        total+=airPlane.airPlaneSeatCount();
    }
    
    return total;
};

std::function<bool(AirPlaneType)> Utility=
[](const AirPlaneType& airPlaneType){

    if(AirPlaneType::NEO==airPlaneType)
    {
        return true;
    }
    return false;
};



