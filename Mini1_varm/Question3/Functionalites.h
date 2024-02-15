#ifndef FUNCTIONALITES_H
#define FUNCTIONALITES_H

#include "Hotel.h"
#include<vector>

using HotelPointer=std::shared_ptr<Hotel>;
using HotelContainer=std::vector<HotelPointer>;


void createHotels(HotelContainer& Hotels);

void DisplayHotelTaxGreaterThan1000(HotelContainer& Hotels);

float TotalArea(HotelContainer& Hotels);

std::vector<Room> CateogryMatch(HotelContainer& Hotels,CategoryType cat);

bool CheckLocation(HotelContainer& Hotels);

#endif // FUNCTIONALITES_H
