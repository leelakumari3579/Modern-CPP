



#ifndef CONTAINEREMPTYINSTANCEEXCEPTION_H
#define CONTAINEREMPTYINSTANCEEXCEPTION_H

#include <iostream>
#include <cstring>
class ContainerEmptyException : public std::exception
{
private:
    char *_msg;

public:
    ContainerEmptyException() = delete;
    ContainerEmptyException(const char *msg)
    {
        _msg=new char[strlen(msg)+1];
        strcpy(_msg, msg);
    }
    ContainerEmptyException(const ContainerEmptyException &other)
    {
        _msg=new char[strlen(other._msg)+1];
        strcpy(_msg,other._msg);
    }
    ContainerEmptyException(ContainerEmptyException &&) = default;
    ContainerEmptyException &operator=(const ContainerEmptyException &) = default;
    ContainerEmptyException &operator=(ContainerEmptyException &&) = default;


    virtual const char *what()
    {
        return _msg;
    }

    ~ContainerEmptyException()
    {
        delete _msg;
    }
};




#endif // CONTAINEREMPTYINSTANCEEXCEPTION_H
