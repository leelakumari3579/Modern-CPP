#include"Functionalities.h"
#include<iostream>


int MaxPowerOver300(std::shared_ptr<ElectricVehicle>& evptr)  // Global Function
{
        int MaxPower = evptr->motor().get().maxPower();

        if(MaxPower>300)
        {
            return MaxPower;
        }
        return 0;
}

int main()
{
    Container data;    // Container which stores all instances of the shared Pointer
    
    ContainerMotor dataMotor;   // Container which stores all instgances of the Motor

    CreateObjects(data,dataMotor);

    // try
    // {
    // std::variant<float,unsigned int> result = AcceptsIdReturnsTorqueOrPower(data,"123"); 
    
    //     std::visit([](auto&& val){std::cout<<"the Result of the Functions is "<<val<<std::endl;},result);
        
    // }
    // catch(EmptyContainerException& emp)
    // {
    //     std::cout<<emp.what()<<std::endl;
    // } 
    // catch(ValidDataNotFoundException& val)
    // {
    //     std::cout<<val.what()<<std::endl;
    // }  
    
//     try
//     {
//         DisplaysBatteryDrain(data);         //Function 2
//     }
//     catch(EmptyContainerException& emp)
//     {
//         std::cout<<emp.what()<<std::endl;
//     }


//     try{                                    //Function 3

//     Container AllInstancesOfEvSharedPointer = FilterData(data,MaxPowerOver300);

//    for(ElectricVehiclePointer& evptr : AllInstancesOfEvSharedPointer)
//    {
//         std::cout<< *evptr<<std::endl;
//    }

//     }
//     catch(EmptyContainerException& emp)
//     {
//         std::cout<<emp.what()<<std::endl;
//     }
//     catch(NoInstanceFoundException& err)
//     {
//         std::cout<<err.what()<<std::endl;
//     }
        

                                    //Logic 5

//    int CombinedMaxPower = (*data[0]).motor().get() + (*data[data.size()-1]).motor().get();

//    std::cout<<"the Combined Power is "<<CombinedMaxPower<<std::endl;


    std::cout<<"Above Operation"<<std::endl;

     PerformOperator(data);

}
