#include<algorithm> 
#include<iostream>
#include<string>
int main()
{
    std::string arr[]={"leela","mounika","sravya","yamini","sireesha"};

    std::string *ptrBegin = std::begin(arr);
    std::string *ptrEnd = std::end(arr);
    while(ptrEnd!=ptrBegin)
    {
    std::string *ptrMax = std::max_element(ptrBegin,ptrEnd);
    std::cout<<"largest element "<<*ptrMax<<std::endl;

    std::swap(*ptrMax,*(ptrEnd-1));
    
    for(std::string *p=std::begin(arr);p!=std::end(arr);p++)
        std::cout<<*p<<" ";
    std::cout<<std::endl;
    ptrEnd--;
    }
    return 0;
}