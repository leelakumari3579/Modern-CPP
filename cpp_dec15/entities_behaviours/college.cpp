#include<iostream>
class college
{
private:
    std::string studentName;
    int rollno;
    std::string department; 
public:
    college(std::string name,int r_no,std::string branch)
    {
        studentName=name;
        rollno=r_no;
        department=branch;
    }
    void displayStudent()
    {
        std::cout<<"student name: "<<studentName<<std::endl;
        std::cout<<"roll number: "<<rollno<<std::endl;
        std::cout<<"department: "<<department<<std::endl;
    }
};

int main()
{
    college clg("Leela",5,"BTECH - CSE");
    clg.displayStudent();
    college clg2("mounika",7,"BTECH - ECE");
    clg2.displayStudent();
}