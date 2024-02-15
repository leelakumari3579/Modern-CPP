#include<iostream>
#include "Functionalities.h"
int main(int argc, char const *argv[])
{   
   /*
   1 Create Objects
   */
   DeviceContainer devices;
   CreateObjects(devices);

   /*
   2. Find Tax Amount: of particular Device Smartpointer
   */
  std::cout<< "Find Tax Amount: of particular Device Smartpointer" <<std::endl;
  try
  {
    FindTaxAmount(devices[0]);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
  std::cout<< "------------------------------------------------------"<<std::endl;
  /*
  3.Display SAR  && price Device
  */
 std::cout<< "Display SAR  && price Device"<<std::endl;
 try
  {
    DisplaySarAndPrice(devices[0]);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
    std::cout<< "------------------------------------------------------"<<std::endl;

std::cout<< " Display SAR  && price Device"<<std::endl;
  /*
  4.Display Id and name
  */
 try
  {
    DisplayIdName(devices[0]);
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }
    std::cout<< "------------------------------------------------------"<<std::endl;

    return 0;
}
