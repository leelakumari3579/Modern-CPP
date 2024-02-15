#include"Functionalities.h"
#include<iostream>

int main()
{
    Container data;
    ContainerPlane dataPlane;
    FunContainer FunC;
    CreateObjects(data,dataPlane);

    MakeLambdaq3(FunC);     // Collections of Lambda Functions

    try{
    Operation(data,FunC);
    }
    catch(EmptyContainerException& empt)        //Exception 
    {
        std::cout<<empt.what()<<std::endl;
    }
    
}