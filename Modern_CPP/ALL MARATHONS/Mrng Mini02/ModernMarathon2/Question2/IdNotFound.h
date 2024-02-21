#ifndef IDNOTFOUND_H
#define IDNOTFOUND_H


#include<exception>
#include<cstring>
#include<iostream>
class IdNotFound : public std::exception
{
private:
     char* _msg;
public:
    IdNotFound() =delete;
    explicit IdNotFound(const char* msg){
     // std::cout<<"Exception called in para "<<std::endl;
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    IdNotFound(const IdNotFound& obj)
    {
        (*this)._msg = new char[strlen(obj.msg())+1];
        strcpy((*this)._msg,obj.msg());
        
    }
    IdNotFound& operator=(const IdNotFound&)=default;
    IdNotFound(IdNotFound&&)=default;
    IdNotFound& operator=(IdNotFound&&)=delete;
    ~IdNotFound()
    {
        delete _msg;
    }

    virtual char* what()
    {
        return _msg;
    }

    char* msg() const { return _msg; }
    
};






#endif // IDNOTFOUND_H
