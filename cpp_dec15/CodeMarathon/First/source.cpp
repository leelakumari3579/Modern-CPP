#include "header.h"
#include<iostream>
#include<cstring>
User::User()
{
    Userid="0000";
    Username="NA";
    Department="NA";
}

User::User(std::string ud, std::string un, std::string dt)
{
    Userid=ud;
    Username=un;
    Department=dt;
}

void operator>>(std::istream &is, User &u1)
{
    is>>u1.Userid;
    is>>u1.Username;
    is>>u1.Department;
}
bool operator==(User &u1, User &u2)
{
    return u1.Department==u2.Department;
}

void search(User *u,std::string dpt,int count=0)
{
    for(int i=0;i<3;i++)
    {
    if(u[i].department()==dpt)
    {
        std::cout<<u[i].username();
        count++;
    }
  
    }
      if(count==3)
        throw"user not fount with same department";
}