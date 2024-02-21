

#ifndef NEGATIVEVALUEEXCEPTION_H
#define NEGATIVEVALUEEXCEPTION_H

#include <iostream>
#include <cstring>
class NegativeValueException : public std::exception
{
private:
    char *_msg;

public:
    NegativeValueException() = delete;
    NegativeValueException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }
    NegativeValueException(const NegativeValueException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    NegativeValueException(NegativeValueException &&) = default;
    NegativeValueException &operator=(const NegativeValueException &) = default;
    NegativeValueException &operator=(NegativeValueException &&) = default;


    virtual const char *what()
    {
        return _msg;
    }

    ~NegativeValueException()
    {
        delete _msg;
    }
};








#endif // NEGATIVEVALUEEXCEPTION_H
