#include<algorithm> //max, min, max_element, min_element
#include<iostream>
#include<string>
int main()
{
    int arr[]={8,1,24};
    //write a program to find the largest element in an array using max_element
    //also print the index of largest element
    int *p=std::max_element(arr,arr+3);
    std::cout<<"max value "<<*p;
    std::cout<<"\nmax value index position "<<p-arr;
   // std::cout<<std::max_element(arr,arr+3)<<std::endl; //gives address
    std::cout<<"\n"<<std::max_element(std::begin(arr),std::end(arr))<<std::endl;
    return 0;
}