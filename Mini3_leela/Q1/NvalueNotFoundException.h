#ifndef NVALUENOTFOUNDEXCEPTION_H
#define NVALUENOTFOUNDEXCEPTION_H

#include <stdexcept>
#include <cstring>

class NvalueNotFoundException
{
private:
    char *_msg;

public:
    NvalueNotFoundException() = delete;
    explicit NvalueNotFoundException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    NvalueNotFoundException(const NvalueNotFoundException &) = default;
    NvalueNotFoundException &operator=(const NvalueNotFoundException &) = delete;
    NvalueNotFoundException &operator=(NvalueNotFoundException &&) = delete;
    NvalueNotFoundException(NvalueNotFoundException &&) = default;
    ~NvalueNotFoundException() = default;

    virtual const char *what() { return _msg; }
};

#endif // NVALUENOTFOUNDEXCEPTION_H
