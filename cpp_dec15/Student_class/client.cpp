#include<iostream>
#include"header.h"

//every non static member function has [this] pointer
void search(Student s[],int r)
{

}
float maxAvg(Student s[],int size)
{
    float avg[size];
    for(int i=0;i<size;i++)
    {
        avg[i]=s[i].calAvg();
        std::cout<<"avg value "<<avg[i]<<std::endl;
    }
    float max=avg[0];
    for(int i=0;i<size;i++)
    {
        if(avg[i]>max)
            max=avg[i];
    }
    return max;
}

int main()
{
    int m1[3]={99,89,90};
    int m2[3]={30,70,85};
    int m3[3]={75,89,74};
    int m4[4]={75,89,100};
    Student s[4]={{1,"lee",m1},{2,"mouni",m2},{3,"srav",m3},{4,"sai",m4}};
    std::cout<<"maximum avg = "<<maxAvg(s,4)<<std::endl;
/*
    //every non static member function can be called by object only
    Student::showX();

    const Student s4;
    s4.display(); //const objects can call const member functions only

    Student *sptr1=new Student();
    sptr1->display();

    Student *sptr2=new Student(104,"ravi",80);
    sptr2->display();

    int n;
    std::cout<<"how many students "<<std::endl;
    std::cin>>n;
    Student *sp=new Student[n];
    */

    Student sarr[3]={{101,"sai",89},{102,"devi",97},{103,"ruchi",87}};
    for(int i=0;i<3;i++)
    {
        //sarr[i].accept();
        sarr[i].display();
    }
    search(sarr,102);
    
    //Student s1; //object of student class / instance of a class.(instance fields)
    //s1.display();
    //std::cout<<s1.rollno;
    //std::cout<<sizeof(Student);

   /* Student s2(5,"leela",70.5);
    s2.display();
    s2.setMarks(94);
    std::cout<<"updated marks = "<<s2.getMarks();
*/
    return 0;
}
