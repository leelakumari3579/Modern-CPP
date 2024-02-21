#include<iostream>
#include"header.h"
#include<cstring>

int Email::emailCount=0; //initialise static member

Email::Email(char senderName[], char receiverName[], char msg[])
{
    // sender= new char[strlen(senderName)+1];
    strcpy(sender,senderName);
    // receiver= new char[strlen(receiverName)+1];
    strcpy(receiver,receiverName);
    // message= new char[strlen(msg)+1];
    strcpy(message,msg);
   // mailCount = emailCount;
    emailCount++;
}

Email::Email()
{
    // sender=new char[10];
    strcpy(sender,"mounika");
    // receiver=new char[20];
    strcpy(receiver,"leela");
    // message=new char[10];
    strcpy(message,"with regards");
    emailCount++;
}

Email::~Email()
{
    // delete []sender;
    // delete []receiver;
    // delete []message;
    // emailCount--;
}
void Email::Display()
{
    std::cout<<"sender: "<<sender<<std::endl;
    std::cout<<"receiver: "<<receiver<<std::endl;
    std::cout<<"message: "<<message<<std::endl;
}

void Email::Send()
{
    std::cout<<"sending email...."<<std::endl;
    std::cout<<"email sent from...."<<sender<<" to "<<receiver<<std::endl;
}

void Email::Receive()
{
    std::cout<<"receiving email...."<<std::endl;
    std::cout<<"email received by...."<<receiver<<" from "<<sender<<std::endl;
}

void Email::Delete()
{
    std::cout<<"deleting mail...."<<std::endl;
    delete this;
}

int Email::getCount()
{
    return emailCount;
}
