#include <functional>
#include <iostream>
#include <cstring>
#include "/home/kpit/M_CPP/Employee/HR.cpp"
#include "/home/kpit/M_CPP/Employee/Employee.cpp"

//patial function
//patial function g(x) is based on f(x,y)

int formula(int x, int y, int z)
{
    return ((x+y)-z);
}

int main()
{
    std::cout<<"formula funtion "<<formula(10,20,30)<<std::endl;

    auto fn = std::bind(formula,std::placeholders::_1, std::placeholders::_2,30); //formula(50,40,30)
    int res = fn(50,40); //3rd parameter never passed. assumed as 30
    std::cout<<"formula funtion with bind "<<res<<std::endl;  

    auto fn2 = std::bind(formula, std::placeholders::_3, std::placeholders::_1, 30); //formula(40,30,50)
    int res2 = fn(50,40); // 2rd parameter never passed. assumed as 30
    std::cout<<"formula funtion with bind "<<res2<<std::endl;  

    fn2(1,2,4,5,6,77); //it will take 3rd parameter first and--- - 1st parameter second and then----30

    auto bindstrcpy = std::bind(strcpy, std::placeholders::_2, std::placeholders::_1); 
    // std::cout<<bindstrcpy("leela","nani");


    //lambda function binded
    auto l1 = [](int x, int y, int z)->int{return ((x+y)-z);};

    auto binded_lambda = std::bind(l1, std::placeholders::_3,std::placeholders::_1, 2000);
    int res3 = binded_lambda(10,20,40); //l1 is exxecuted with l1(40,10,200)
    std::cout<<"result lambda"<<res3<<std::endl;


    HR h1(101,"lee",890000.0f,10,HRSpecialization::PMT);
    auto bind_calculateTax = std::bind(&HR::CalculateTax,&h1);
    std::cout<<"tax "<<bind_calculateTax()<<std::endl; //h1.CalculateTax
}