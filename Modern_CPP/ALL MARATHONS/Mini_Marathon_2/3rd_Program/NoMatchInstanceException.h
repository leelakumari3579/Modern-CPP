#ifndef NOMATCHINSTANCEEXCEPTION_H
#define NOMATCHINSTANCEEXCEPTION_H

#include <iostream>
#include <cstring>
class NoMatchInstanceException : public std::exception
{
private:
    char *_msg;

public:
    NoMatchInstanceException() = delete;
    NoMatchInstanceException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }
    NoMatchInstanceException(const NoMatchInstanceException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    NoMatchInstanceException(NoMatchInstanceException &&) = default;
    NoMatchInstanceException &operator=(const NoMatchInstanceException &) = default;
    NoMatchInstanceException &operator=(NoMatchInstanceException &&) = default;


    virtual const char *what()
    {
        return _msg;
    }

    ~NoMatchInstanceException()
    {
        delete _msg;
    }
};






#endif // NOMATCHINSTANCEEXCEPTION_H
