#include <iostream>
//class with virtual fun is called as polymorphic class
//class without virtual fun is concrete class
//class with pure virtual fun is called as abstract class
class Employee//base class/parent class
{
protected:
    double esalary;
//protected -can be accessed by member functions of same class and derive class 

private:
    int empid;
    std::string ename;

    double MA, PTAX, PF;
    void calExpenses() // helper functions-are private funs and they help public funs
    {
        MA = esalary * 0.05;
        PTAX = esalary * 0.04;
        PF = esalary * 0.03;
    }

public:
    Employee()
    {
        std::cout << "\n Employee() called ";
        empid = 1;
        ename = "Yash";
        esalary = 60000;
        calExpenses();
    }
    Employee(int eid, std::string nm, double esal)
        : empid(eid), ename(nm), esalary(esal)
    {
        std::cout << "\n Employee(....) called ";
        calExpenses();
    }
   virtual void accept()
    {
        std::cout << "\n enter id ";
        std::cin >> empid;
        std::cout << "\n enter name ";
        std::cin >> ename;
        std::cout << "\n enter salary ";
        std::cin >> esalary;
    }
    //function overriding-kind of run time polymorphism
//fun with same name ,same return type,same parameters**in hierarchy of classes
   virtual void display()
    {
        std::cout << "\n ************\nEmployee details " << empid << " " << ename << " " << esalary;
    }
    virtual double calTotalSalary()
    {
         std::cout<<"\n In Emp calTotalsalary() ";
        return esalary + MA - PTAX - PF;
    }
    friend std::ostream &operator<<(std::ostream &os, Employee &e)
    {
        os << "\t " << e.empid << " " << e.ename << " " << e.esalary;
        return os;
    }
    virtual ~Employee()
    {
        std::cout << "\n ~Employee() called ";
    }
};