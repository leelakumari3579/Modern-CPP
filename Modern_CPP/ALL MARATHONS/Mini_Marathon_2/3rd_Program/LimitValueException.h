

#ifndef LIMITVALUEEXCEPTION_H
#define LIMITVALUEEXCEPTION_H

#include <iostream>
#include <cstring>
class LimitValueException : public std::exception
{
private:
    char *_msg;

public:
    LimitValueException() = delete;
    LimitValueException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }
    LimitValueException(const LimitValueException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    LimitValueException(LimitValueException &&) = default;
    LimitValueException &operator=(const LimitValueException &) = default;
    LimitValueException &operator=(LimitValueException &&) = default;


    virtual const char *what()
    {
        return _msg;
    }

    ~LimitValueException()
    {
        delete _msg;
    }
};







#endif // LIMITVALUEEXCEPTION_H
