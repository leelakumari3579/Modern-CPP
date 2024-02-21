#ifndef VALUENOTFOUND_H
#define VALUENOTFOUND_H

#include<exception>
#include<cstring>
#include<iostream>
class ValueNotFound : public std::exception
{
private:
     char* _msg;
public:
    ValueNotFound() =delete;
    explicit ValueNotFound(const char* msg){
     // std::cout<<"Exception called in para "<<std::endl;
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    ValueNotFound(const ValueNotFound& obj)
    {
        (*this)._msg = new char[strlen(obj.msg())+1];
        strcpy((*this)._msg,obj.msg());
        
    }
    ValueNotFound& operator=(const ValueNotFound&)=default;
    ValueNotFound(ValueNotFound&&)=default;
    ValueNotFound& operator=(ValueNotFound&&)=delete;
    ~ValueNotFound()
    {
        delete _msg;
    }

    virtual char* what()
    {
        return _msg;
    }

    char* msg() const { return _msg; }
    
};



#endif // VALUENOTFOUND_H
