#include <iostream>
#include <cstring>
/*
containment -  has a relation / is a part of
 Why ?- reusability
*/
class MyDate
{
    int day, month, year;

public:
    MyDate()
    {
        std::cout << "\n MyDate() called... ";
        day = 1;
        month = 1;
        year = 2023;
    }
    MyDate(int d, int m, int y)
    {
        std::cout << "\n MyDate(...) called... ";
        day = d;
        month = m;
        year = y;
    }
    friend std::ostream &operator<<(std::ostream &os, const MyDate &m)
    {
        os << m.day << "/" << m.month << "/" << m.year << std::endl;
        return os;
    }
    void display()
    {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};
class Person // container class
{
    char name[20];
    MyDate dob; // contained object

public:
    Person(const char nm[], MyDate md):dob(md)
    {
        std::cout << "\n Person(...) called... ";
        // nm=new char[strlen(nm)+1];
        strcpy(name,nm);
    }
    Person()
    {
        std::cout << "\n Person() called... ";
        strcpy(name, "Gagan");
    }
    friend std::ostream &operator<<(std::ostream &os, const Person &pr)
    {
        os << "\n"<< pr.name << pr.dob << std::endl;
        return os;
    }
    void display()
    {
        std::cout << name;
        dob.display();
    }
};

int main()
{
    Person p1("Amit ",MyDate(2,3,2004) );
    // p1.display();
    std::cout << p1;
    

    // Person p;
    // std::cout << p;
    // p.display();

    /* MyDate d1,d2;
    std::cout<<d1<<d2;
    cout<<d1              <<d2
    operator<<(cout,d1)   <<d2
    operator<<(cout,d2)
    */
}