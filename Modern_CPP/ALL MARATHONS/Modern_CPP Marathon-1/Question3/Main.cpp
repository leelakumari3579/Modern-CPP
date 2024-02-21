#include "Functionalities.h"
#include<iostream>
int main(int argc, char const *argv[])
{
    /*
    fun1 : Create Hotels
    */
   
    HotelContainer hotels;
   
    createHotels(hotels);
/*
Fun2  DisplayHotelTaxGreaterThan1000*/
    try
    {
        DisplayHotelTaxGreaterThan1000(hotels);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

   

/*Fun3 TotalArea of rooms */
     try
    {
        std::cout<<"Total Area: "<<TotalArea(hotels)<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

/*
    CateogryMatch  fun 4
*/  
    std::cout<<"Category of Match"<<std::endl;
      try
    {
       std::vector<Room> ans=CateogryMatch(hotels,CategoryType::MOTEL);
       for(auto & a:ans)
       {
       std::cout<<a<<"\n";
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

/*

    Fun5:  check location of all hostels
*/
try
    {
       if(CheckLocation(hotels)){
        std::cout<< "All are in same location"<<std::endl;
       }else{
         std::cout<< "All are not in same location"<<std::endl;
       }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}
