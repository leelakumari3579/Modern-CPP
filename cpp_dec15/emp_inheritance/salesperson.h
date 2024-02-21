#include"Emp.h"
//derived class 
class Salesperson : public Employee
{
    double salesamount,commissionrate;
    public:
        void calculateCommission()//special fun of Salesperson class
        {
            std::cout<<"\nCommission amount  ="<<salesamount*commissionrate;
        }
        Salesperson()
        {
            std::cout<<"\n Salesperson() called ";
            salesamount=15000;
            commissionrate=0.05;
        }
        Salesperson(int eid, std::string nm, double esal,double samt,double cm)
        : Employee(eid,nm,esal),salesamount(samt),commissionrate(cm)
        {
             std::cout<<"\n Salesperson(..) called ";
        }
        void display()
        {
            Employee::display();
            std::cout<<"\t salesamt = "<<salesamount<<" crate = "<<commissionrate;
        }
         double calTotalSalary()
        {
            std::cout<<"\n In Sp calTotalSalary() ";
            //return Employee::calTotalSalary()+salesamount*commissionrate;
            return esalary+salesamount*commissionrate;
        }
        friend std::ostream& operator<<(std::ostream & os,Salesperson &sp)
        {
            os<<"\n salesamt = "<<sp.salesamount<<" comm= "<<sp.commissionrate;
            //Employee e = sp; // object slicing 
            os<<  static_cast<Employee&>(sp) ;
            return os;
        }
        ~ Salesperson()
        {
            std::cout<<"\n ~Salesperson() called ";
        }
};