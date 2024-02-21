#include<iostream>
#include"header.h"
#include<cstring>
student::student(int rollno,const char *s_name, int *scores):id(rollno)
{
    strcpy(name,s_name); 
    for(int i=0;i<3;i++)
    {
        marks[i]=scores[i];
    }
}

 student::student()
{
    id=7;
    strcpy(name,"leela");
    for(int i=0;i<3;i++)
    {
        marks[i]=0;
    }
}

student::~student()
{
    std::cout<<"deleted "<<std::endl;
}

void student::display()const
{
    std::cout<<"id= "<<this->id<<std::endl;
    std::cout<<"name= "<<this->name<<std::endl;
    std::cout<<"marks= "<<marks[0]<<" "<<marks[1]<<" "<<marks[2]<<std::endl;
}

float student::avg()
{
    float avg=0;
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum += marks[i];
        avg=sum/3;
    }
    return avg;
}
