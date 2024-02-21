#include<iostream>
#include<cstring>
class Employee
{
    char empname[30];

    public :
        Employee(){ strcpy(empname,"AAAAA") ;}
         Employee(const char *n){ strcpy(empname,n) ;}
         void display()
         {
            std::cout<<empname<<std::endl;
         }
         char& operator[](int index)
         {
            if(!(index>=0 && index<strlen(empname)))
              throw "Index out of bounds ";
            return empname[index];  
         }
};
int main()
{
    Employee e1("Abhishek");
    //std::cout<<e1[0];
    try
    {
    char ch = e1[899];
    std::cout<<"ch = "<<ch<<std::endl;
    // char ch= e1.opearator[](0)
    /*LHS  RHS
      char ch= function call on right side of assignment opearator
        
    */
    }
    catch(const char *msg)
    {
        std::cout<<"\n "<<msg;
    }

    e1[1]='a';
    e1.display();

    /*
      e1.operator[](1) = 'a'
      funcall on left side = 'a'     
    */


    return 0;
}