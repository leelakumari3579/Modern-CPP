#include <iostream>

class Employee
{
private:
    int _eid;
    std::string _ename;
public:
    Employee(int id, std::string name) :_eid(id),_ename(name) {}
    Employee() = delete;
    Employee(const Employee&)
    {
        std::cout<< "copy constructor called\n";
    }
    Employee& operator=(const Employee&)
    {
        std::cout<< "copy assignment constructor called\n";
        return *this;
    }
    Employee(Employee&&)
    {
        std::cout<< "Move constructor called\n";
    }
    Employee& operator=(Employee&&)
    {
        std::cout<< "Move assignment constructor called\n";
        return *this;
    }
    ~Employee() = default;
};

Employee Magic(int id, std::string name)
{
    std::cout<< "Middle man!!\n";
    return Employee(id,name);
}

//Employee e1 = WHATEVER IS RETURNED FROM Magic
//Employee e1 is assigned whatever is returned from magic

//Employeee1 is assigned a rvalue

int main()
{
    Employee e1 = Magic(101,"leela");
}
/*
    IF NO OPTIMIZATION 
        step1: we go to magic function
        step2: return an rvalue
        step3: rvalue should be assigned to e1
        WHICH MEANS E1 SHOULD BE ATTACHED TO MY DATA

    WITH OPTIMIZATION
        step1: we go to magic function. 
            I know the address in main where data needs to be returned
        step2: return Employee(101,"leela") basically means write 101, leela
            in the location in main which you already know! 
*/