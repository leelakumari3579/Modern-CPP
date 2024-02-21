
#ifndef CREATECHECK_H
#define CREATECHECK_H

#include<exception>
#include<cstring>
#include<iostream>
class CreateCheck : public std::exception
{
private:
     char* _msg;
public:
    CreateCheck() =delete;
    explicit CreateCheck(const char* msg){
     // std::cout<<"Exception called in para "<<std::endl;
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    CreateCheck(const CreateCheck& obj)
    {
        (*this)._msg = new char[strlen(obj.msg())+1];
        strcpy((*this)._msg,obj.msg());
        
    }
    CreateCheck& operator=(const CreateCheck&)=default;
    CreateCheck(CreateCheck&&)=default;
    CreateCheck& operator=(CreateCheck&&)=delete;
    ~CreateCheck()
    {
        delete _msg;
    }

    virtual char* what()
    {
        return _msg;
    }

    char* msg() const { return _msg; }
    
};




#endif // CREATECHECK_H
