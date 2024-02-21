#ifndef NOCARFOUNDEXECEPTION_H
#define NOCARFOUNDEXECEPTION_H

#include<iostream>
#include<cstring>
class NOCarFoundExeception :public std::exception
{
private:
      char* _msg;
public:
   
   NOCarFoundExeception()=delete;
   NOCarFoundExeception(const NOCarFoundExeception&)=delete;
   NOCarFoundExeception(NOCarFoundExeception&&)=default;
   NOCarFoundExeception& operator=(const NOCarFoundExeception&)=delete;
   NOCarFoundExeception& operator=(NOCarFoundExeception&&)=default;
   ~NOCarFoundExeception()=default;
     char* what()  {return _msg;};
    explicit NOCarFoundExeception(const char* msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    };
   
};


#endif // NOCARFOUNDEXECEPTION_H
