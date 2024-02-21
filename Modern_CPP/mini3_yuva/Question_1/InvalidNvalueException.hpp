#ifndef INVALIDNVALUEEXCEPTION_HPP
#define INVALIDNVALUEEXCEPTION_HPP

#include<stdexcept>
#include<cstring>

class InvalidNvalueException:public std::exception
{
private:
    char* _msg;
public:
    InvalidNvalueException()=delete;
    InvalidNvalueException(const InvalidNvalueException& rhs)
    {
        _msg=new char[strlen(rhs._msg)+1];
        strcpy(_msg,rhs._msg);
    }
    InvalidNvalueException(InvalidNvalueException&&)=delete;
    InvalidNvalueException& operator=(const InvalidNvalueException& rhs)
    {
        _msg=new char[strlen(rhs._msg)+1];
        strcpy(_msg,rhs._msg);
        return *this;
    }
    InvalidNvalueException& operator=(InvalidNvalueException&&)=delete;
    ~InvalidNvalueException()
    {
        delete _msg;
    }

    InvalidNvalueException(const char* msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg,msg);
    }
    virtual const char* what()
    {
        return _msg;
    }

};


#endif // INVALIDNVALUEEXCEPTION_HPP
