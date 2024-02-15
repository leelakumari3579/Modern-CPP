#ifndef IDNOTFOUNDEXCEPTION_H
#define IDNOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <cstring>

class IdNotFoundException : public std::exception
{
private:
    char* _msg; 
public:
    IdNotFoundException() = delete;
    explicit IdNotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    IdNotFoundException(const IdNotFoundException&) = default;
    IdNotFoundException& operator=(const IdNotFoundException&) = delete;
    IdNotFoundException& operator=(IdNotFoundException&&) = delete;
    IdNotFoundException(IdNotFoundException&&) = default;
    ~IdNotFoundException() = default;  

    virtual const char* what(){ return _msg;}
};

#endif // IDNOTFOUNDEXCEPTION_H
