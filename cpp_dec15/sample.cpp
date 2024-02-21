#include<iostream>
#include<cstring> //string header from C library.
//using namespace std;
//cout - object of ostream class
//cin - object of iostream class
//<< - insertion operator
//>> - extraction oprator
int main()
{
    char str[30]="learning cpp";
    int len=strlen(str);
    std::cout<<"\n length = "<<len<<std::endl;
    return 0;
}
//cascading effect
//memory allocation
//instead of malloc function for integers --> int n=10;  int *arr = new int[n];
//for strings -->char*cptr = new char[20];
//for freeing the memory -->delete arr; OR delete []cptr;
//use delete to avoid memory leakage
//void fun(int a) -->pass by value
//void fun(int *a) -->pass by address  
//reference variable  int b = 20;
//                    int &r = b; -->give nick/alias name
// address            int *p = &b;

//swaping using pass by reference
//try pointer using pass by refernce
