#include<iostream>
#include<cstring>
#include"header.h"

int Student::x=10;

// return type clasaname::funName(){ }

void Student::accept()
{

}

void Student::display()const
{
    std::cout<<"roll no : "<<rollno<<std::endl;
    std::cout<<"name : "<<name<<std::endl;
    std::cout<<"marks : "<<marks<<std::endl;
}

Student::Student()//default constructor will not take any parameters 
{
    std::cout<<"in student default constructor"<<std::endl;
    rollno=202;
    strcpy(name,"nani");
    marks=99.0;
}

Student::Student(int r, const char *nm, int s[])
{
    rollno=r;
    strcpy(name,nm);
    for(int i=0;i<3;i++)
    {
        sub[i]=s[i];
    }
}

float Student::calAvg()
{
    int sum=0;
    for(int i=0;i<3;i++)
    {
        sum +=sub[i];
    }
    return sum/3.0f;
}

//r nm m are local variables.
Student::Student(int r,const char *nm,double m): //perameterised constructor
    rollno(r),marks(m)
{
    std::cout<<"in student perametarised constructor"<<std::endl;
   // rollno=r;
    strcpy(name,nm);
   // marks=m;
    //this->marks=marks;
}

//void Student::search(Student s[],int r)
//{
//}


void Student::showX()//can access static members only
{
    std::cout<<"\n x= "<<x;
}
