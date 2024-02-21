#include<iostream>
#include<cstring>
#include"header.h"

int Student::x=10;
int Student::cnt=501;

// returntype  classname::funname(){   }

void Student::accept()
{
// accept only name & marks 
}

void Student::display()const
{
    std::cout<<"\n rollno ="<<rollno<<" Name ="<<name<<" marks ="<<marks;
}
Student::Student()
{
    std::cout<<"\n In Student() ctor ";
    rollno=cnt;
    cnt++;
    strcpy(name,"AAA");
    marks=90.55;
}
// r , nm , m are local variables
Student::Student(const char *nm,double m):
     marks(m)
{
    rollno=cnt;
    cnt++;
    std::cout<<"\n In para Student() ctor ";
    strcpy(name,nm);
  
}

void Student::showX()// can access static members only
{
    std::cout<<" \n x= "<<x;
    // this pointer is never passed to static functions
    //rollno=9;
}
