#include<iostream>
#include"header.h"
int main()
{
    Email mail;
    mail.Display();
    //using instances of the email class
    char em1[50]="leelasdasdsssssd";
    char em2[50]="leelasdasdsssssd";
    char em3[50]="leelasdasdsssssd";
    Email m(em1,em2,em3);
    // Email m("mounika@gmail.com","sravya@gmail.com","thanthe eguruthav...");
    m.Display();

    // Email* mail1=new Email("sender@gmail.com","receiver@gmail.com","how are you doing?");
    // Email* mail2=new Email("leela@gmail.com","nani@gmail.com","loving you <'-'>");
    // Email* mail3=new Email("mounika@gmail.com","sravya@gmail.com","thanthe eguruthav...");

    //using email functionalities
    // mail1->Display();
    // mail1->Send();
    // mail2->Receive();
    // mail3->Receive();
    // mail3->Display();
    // mail1->Delete();
    // mail1->Display();

    //static method can be called using class name
    std::cout<<"total emails after deletion: "<<Email::getCount()<<std::endl;
    return 0;
}