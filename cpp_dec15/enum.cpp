#include <iostream>
#include <cstring>
enum HOBBIES
{
    READING,
    DANCING,
    TRAVELLING
};
class Person
{
    char name[20];
    enum HOBBIES hb;

public:
    Person()
    {
        strcpy(name, "Joy");
        hb = READING;
    }
    Person(const char *nm,enum HOBBIES h)
    {
        strcpy(name,nm);
        hb=h;
    }
    void accept()
    {
        std::cout << "\n Enter name";
        std::cin >> name;
        std::cout << "\n Enter hobby 0-READING,1-DANCING,2-TRAVELLING";
        int h;
        std::cin >> h;
        switch (h)
        {
        case 0:
            hb=READING;
            break;
        case 1:
            hb=DANCING;
            break;
        case 2:
            hb=TRAVELLING;
            break;
        }
    }
     void display()
    {
        std::cout << "\n  name "<< name;
        std::cout << "\n hobby ";
         
        switch (hb)
        {
        case 0:
            std::cout<<"\t READING";
            break;
        case 1:
           std::cout<<"\t DANCING ";
            break;
        case 2:
            std::cout<<"\t TRAVELLING";
            break;
        }
    }
};

int main()
{
    Person p1;
    p1.display();

    p1.accept();
    p1.display();

    return 0;
}