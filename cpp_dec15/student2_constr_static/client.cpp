#include<iostream>
#include"header.h"
//every non static member function has [this] pointer

void addRecord(Student s[],int index)
{
    s[index].accept();
}

void showRecords(Student s[],int totalrec)
{
    for(int i=0;i<totalrec;i++)
    {
        s[i].display();
    }
}

//search record code
void searchRecords(Student s[],int totalrec)
{
    int r=4;
    bool flag=false;
    //enter rollno to serch the record
    for(int i=0;i<totalrec;i++)
    {
        if(s[i].getRollno()==r)
        {
        s[i].display();
        std::cout<<"found "<<std::endl;
        flag=true;
        break;
        }
    }
    if(flag==false)
    {
        std::cout<<" not found";
    }
}
int main()
{
    // Student s1;
    // s1.display();

    // Student s2;
    // s2.display();

    // Student s3("Arun",80);
    // s3.display();

    Student *sp=new Student;
    int n=5;
    Student *sp1=new Student;
    int cr=0; //current record

    delete sp;
    delete sp1;
}