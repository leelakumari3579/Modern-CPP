#ifndef NOMATCHINGINSTANCEEXCEPTION_H
#define NOMATCHINGINSTANCEEXCEPTION_H

#include <stdexcept>
#include <cstring>

class NoMatchingInstanceException : public std::exception
{
private:
    char *_msg;

public:
    NoMatchingInstanceException() = delete;
    // explicit NoMatchingInstanceException(const char* msg) {strcpy(_msg,msg);}
    explicit NoMatchingInstanceException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    NoMatchingInstanceException(const NoMatchingInstanceException &) = default;
    NoMatchingInstanceException &operator=(const NoMatchingInstanceException &) = delete;
    NoMatchingInstanceException &operator=(NoMatchingInstanceException &&) = delete;
    NoMatchingInstanceException(NoMatchingInstanceException &&) = default;
    ~NoMatchingInstanceException() = default;

    virtual const char *what() { return _msg; }
};


#endif // NOMATCHINGINSTANCEEXCEPTION_H
