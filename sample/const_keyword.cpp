#include <iostream>

class Employee{
    private:
    int id;
    public: 
        Employee(int id):id(id){}
        ~Employee()=default;

        void setId(int id_) { id = id_; }
};
//const correctness
/*
    rule1: const gets appalied on token to its immediate left.
    if there is no token on the left, it is applied to the tken on the immediate right.
*/


int main()
{
    //type1: const with a non-pointer primitive variable
    const int n1 = 10; //n1 is a "const integer"
    int const n2 = 20; //n2 is a "const integer"

    //type2: const with a pointer variable of any type
    //*cptr is a pointer to a CONST CHAR
    const char* cptr = new char('A');
    //*cptr = 'B'; //error cannot change data because constant char!
    cptr = new char('B'); //address

    //type3: const applied on *
    int a = 100;
    //iptr is a cont pointer to an integer
    int* const iptr = &a;

    *iptr = 1000; //okay beacause integr can be changed
    //*iptr = &n1; //not okay! because pointer itself is fixed. address cannot change

    //type2c
    //sptr is a const pointer to a cont integer
    const int* const sptr = &a;
    //*sptr = 100; // not allowed
    //sptr = &n1; //not allowed

    //type3: const on a object (refrence type/ user defined type)
    const Employee e1(101); //e1 is a "CONST EMPLOYEE"
    //e1._eid = 100; //cannot modify any data value from the object
    //e1.setId(10); //error not able to modify the constant objects

    //tyep4: constg member functions
    //these are functions that are "safe" for const objects.
    //constant objects ARE ONLY ALLOWED TO CALL MEMBER FUNCTIONS WHICH ARE MARKED AS CONST
}