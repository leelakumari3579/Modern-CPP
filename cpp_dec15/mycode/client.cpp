#include<iostream>
#include"header.h"

int main()
{
    int rollno;
    char name[20];
    int marks[3];
    int n;

    // student s1;
    // s1.display();

    std::cout<<"enter number of students: ";
    std::cin>>n;
    student *std=new student[n];
    for(int i=0;i<n;i++)
    {
        std::cout<<"enter student roll number: "<<std::endl;
        std::cin>>rollno;
        std::cout<<"enter student name: "<<std::endl;
        std::cin>>name;
        std::cout<<"enter student marks: "<<std::endl;
        for(int i=0;i<3;i++)
            std::cin>>marks[i];
        std[i].setId(rollno);
        std[i].setName(name);
        std[i].setMarks(marks);
        std::cout<<std::endl;
    }
    for(int i=0;i<n;i++)
    {
        std[i].display();
    }
    int k=0;
    for(int i=0;i<n;i++)
    {
        std::cout<<"average marks of student "<<i+1<<" is "<<std[i].avg()<<std::endl;
    }
    delete []std;
    return 0;
}
