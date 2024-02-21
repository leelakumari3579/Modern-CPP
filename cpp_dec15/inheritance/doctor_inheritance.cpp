#include<iostream>

class Doctor
{

    public:
   
        virtual void checkpatient()
        {

        }
};
class Dentist:public Doctor
{
public:
        void rootc()
        {
            std::cout<<"\nWelcome to spend money for RC..... ";
        }
        
        void checkpatient()
        {
            
        }

};
class HS: public Doctor
{
    public:void checkpatient()
        {

        }
       
};

int main()
{
    Doctor *dc =  new HS;
    dc->checkpatient();
    
    // type casting
    Dentist *dt = dynamic_cast<Dentist*>(dc);// down cast
    if(dt!=0)
        dt->rootc();
    else
        std::cout<<"\n u r in wrong place ";

}