#ifndef NOCARSAVAIALBLE_H
#define NOCARSAVAIALBLE_H

#include<iostream>
#include<cstring>
class NoCarAvailable :public std::exception
{
private:
      char* _msg;
public:
   
   NoCarAvailable()=delete;
   NoCarAvailable(const NoCarAvailable&)=delete;
   NoCarAvailable(NoCarAvailable&&)=default;
   NoCarAvailable& operator=(const NoCarAvailable&)=delete;
   NoCarAvailable& operator=(NoCarAvailable&&)=default;
   ~NoCarAvailable()=default;
     char* what()  {return _msg;};
    explicit NoCarAvailable(const char* msg){
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    };
   
};


#endif // NOCARSAVAIALBLE_H
