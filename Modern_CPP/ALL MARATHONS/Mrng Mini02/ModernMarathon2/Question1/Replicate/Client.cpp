#include "functionalities.h"
#include<iostream>

int main(){
    std::vector<int>data={1,2,3,4};
    funContainer fn;
    MakeLambda(fn);
    std::cout<<"the number of fucntions in fn "<<fn.size();
    PerformOpearations(fn,data);
}