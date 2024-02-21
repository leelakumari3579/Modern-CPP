#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<vector>
#include<memory>
#include"Flight.h"
#include"AirPlane.h"
#include<functional>


void CreateObjects(std::vector<std::shared_ptr<Flight>>& vectorFlight,std::vector<AirPlane>& vectorAirPlane);

extern std::function<std::vector<AirPlane>(std::vector<std::shared_ptr<Flight>>,FlightOperatorType)> MatchByFlightOperatorType;

extern std::function<AirPlaneType(std::vector<std::shared_ptr<Flight>>)> LowestAirPlaneSeatCount;

extern std::function<std::vector<AirPlane>(std::vector<AirPlane>,int)> ThresholdAirPlaneCount;

extern std::function<int(std::vector<AirPlane>)> TotalAirPlaneSeatCount;

extern std::function<bool(AirPlaneType airplanetype)> Utility;

std::vector<std::shared_ptr<Flight>> FilterData(std::function<bool(AirPlaneType airplanetype)>& fn,std::vector<std::shared_ptr<Flight>>& vectorFlight);


#endif // FUNCTIONALITIES_H
