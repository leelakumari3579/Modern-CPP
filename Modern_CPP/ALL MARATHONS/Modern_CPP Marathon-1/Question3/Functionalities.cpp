#include"Functionalities.h"
#include<iostream>
void createHotels(HotelContainer &Hotels)
{

  
 Hotels.emplace_back(std::make_shared<Hotel>("Balaji",12343,std::make_shared<Room>(323.45f,200000,RoomType::DELUXE),CategoryType::PREMIUM));
  Hotels.emplace_back(std::make_shared<Hotel>("Balaji",12343,std::make_shared<Room>(434.45f,10000,RoomType::LUXURY),CategoryType::MOTEL));
  Hotels.emplace_back(std::make_shared<Hotel>("Balaji",12343,std::make_shared<Room>(534.45f,2200,RoomType::MAPLE),CategoryType::STAY));
  Hotels.emplace_back(std::make_shared<Hotel>("Balaji",12343,std::make_shared<Room>(634.45f,3000,RoomType::DELUXE),CategoryType::MOTEL));
}

void DisplayHotelTaxGreaterThan1000(HotelContainer &Hotels)
{
  if(Hotels.size()==0){
    throw std::runtime_error("No Hotels Present");
  }
  for(auto &hotel : Hotels){

      if(hotel->room()->calculateTaxAmount()>1000.0f){
        // greater than 1000;
        std::cout<<*hotel<<std::endl;
      }
  }
}

float TotalArea(HotelContainer &Hotels)
{ 
    if(Hotels.size()==0){
    throw std::runtime_error("No Hotels Present");
  }
    float ans=0;
    for(auto &hotel : Hotels){
       ans+=hotel->room()->area();
    }
    return ans;
}

std::vector<Room> CateogryMatch(HotelContainer &Hotels,CategoryType cat)
{ 
  if(Hotels.size()==0){
    throw std::runtime_error("No Hotels Present");
  }
    std::vector<Room>arr;
    for(auto &hotel : Hotels){
      if(hotel->category()==cat){
        arr.push_back(*hotel.get()->room());
      }
    }
    if(arr.empty()){
      throw std::runtime_error("No Hotels Matched with given Category");
    }
    return arr;
}

bool CheckLocation(HotelContainer &Hotels)
{
    if(Hotels.size()==0){
    throw std::runtime_error("No Hotels Present");
    }
    int loc=Hotels[0]->locationCode();
    for(auto &hotel : Hotels){
      if(loc!=hotel->locationCode()){
        return false;
      }
    }
    return true;
}