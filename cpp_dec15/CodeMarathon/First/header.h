#ifndef HEADER_H
#define HEADER_H
#include<cstring>
#include<iostream>
// class DepartmentExecption:public std::exception
// {
//     char message[100];
//     public:
//         DepartmentExecption()
//         {
//             strcpy(message,"user not found with same department ");
//         }
//         DepartmentExecption(const char s[])
//         {
//             strcpy(message,s);
//         }
//         char * what()
//         {
//             return message;
//         }
// };
class User
{
    std::string Userid;
    std::string Username;
    std::string Department;
    public:
        User();
        User(std::string,std::string,std::string);
        std::string userid()  { return Userid; }
        void setUserid( std::string &userid) { Userid = userid; }

        std::string username()  { return Username; }
        void setUsername( std::string &username) { Username = username; }   

        std::string department()  { return Department; }
        void setDepartment( std::string &department) { Department = department; }

        friend void operator>>(std::istream &is,User &u1);
        friend bool operator==(User &u1,User &u2);        
};

#endif // HEADER_H
