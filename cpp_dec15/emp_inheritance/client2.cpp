#include<iostream>
#include"salesperson.h"

int main()
{
//     Salesperson sp;
//     sp.display();
//     Employee *p=new Employee;
//     Salesperson s1;
//     Employee *ep = &s1;
//     pointer to base class= holding object of derive class


    Employee* eptr= new Salesperson(11,"Jay",45000,12000,0.5);
    std::cout<<eptr->calTotalSalary();
    eptr->display();

    Salesperson *sp = dynamic_cast<Salesperson*>(eptr);//down cast
    sp->calculateCommission();

    delete eptr;


    //Employee e1;
   // e1.esalary=10000;//protected is not accessible in main() fun


   // Employee e1;
    //Employee e2(501,"Hitesh",90000);
    //std::cout<<"\n Salary  of Employee = "<<e2.calTotalSalary();

    //Salesperson sp;//derived class object 
    //std::cout<<"\n Salary  of Salesperson = "<<sp.calTotalSalary();
    //std::cout<<sp;

    //sp.display();
    
    return 0;
}