#include<iostream>
#include<string>

extern int a;  //only declaration -->gives undefined reference to 'a'
int b;         //declaration and definition
int c=10;       //declaration and definition
int main()
{
    // a=10;
    // b=20;
    std::cout<<a<<std::endl;
    std::cout<<b<<std::endl;
    return 0;
}

//g++ filename.cpp -c
//U ->stads for undefined
//declaration -> tells the type and name of variable (does not reserve memory)
//definition -> reserves memory for the variable
//static to global variable -> internal leakage
//static to global function -> internal leakage
//head -10 sample.cpp -> for reading first 10 lines code in terminal page.
// const references can refer to lval/rval
