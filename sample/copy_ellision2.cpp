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
    Employee(Employee&&) = default;
    // {
    //     std::cout<< "Move constructor called\n";
    // }
    Employee& operator=(Employee&&)
    {
        std::cout<< "Move assignment constructor called\n";
        return *this;
    }
    ~Employee() = default;

    int eid() const { return _eid; }
    void setEid(int eid) { _eid = eid; }

    std::string ename() const { return _ename; }
    void setEname(const std::string &ename) { _ename = ename; }
};

Employee Magic(int id, std::string name)
{
    std::cout<< "Middle man!!\n";
    Employee emp(103,"leelanani");
    return emp;
}

int main()
{
    /*
        we reserve a total of 36 or 52 bytes of memory in main
        this memory is now being indentified by the name e1
        [this makes e1 an lvalue]
    */
    Employee e1 = Magic(101,"leela");

    /*
        we are constructing a new object with identifier name e2
        RIGHT NOW e2, uses memory location that was PREVIOUSLY ATTACHED TO IDENTIFIER e1
    */
    Employee e2 = std::move(e1); //move constructor called --->because of rvalue

    //Employee e3 = e1; //copy constructor called

    //LAO AAG!!!
    std::cout<<e1.ename()<<"\n"; //ILLEGAL!!!! //"leelanani"
    std::cout<<e2.ename()<<"\n"; //prints if move constructor is default....

    e1 = Employee(111,"nani"); //move assignment constructor called --->re-inialised the memory with old memory e1 (get new address)
    std::cout<<e1.ename()<<"\n"; //no change of values "leelanani"

    e2 = std::move(Employee(121,"roshi")); //move assignment constructor called
}


//g++ copy_ellision2.cpp -fno-elide-constructors -g -o app --->checks wether the constructors are called or not

/*
    DISABLE OPTIMIZATION
        step1: you go to magic. retrurn address is known
        step2: make a new local variable emp in the stack of magic
        step3: return emp (this is an rvalue)

        HENCE,
        Employee e1 = Magic(101,"leela")
        Construct a new object e1 in the scope of main an rvalue of type  Employee
*/