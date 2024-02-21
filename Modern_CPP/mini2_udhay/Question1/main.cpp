#include"Functionalities.h"
#include<iostream>
#include<vector>
#include"EmptyContainerException.h"

int main()
{   
    Container data;                 //Container Which Contains the lambda functions
    std::vector<int> inputVector;   // Vector which takes values from the user
    FillingVector(inputVector);     // Function that undergoes filling of the Vector

    MakeLambda(data);               // Pushing every Function
    try
    {

        Operation(data,inputVector);

    }
    catch(EmptyContainerException& emp)     //EmptyContainer Exception
    {

        std::cout<<emp.what()<<std::endl;

    }

}