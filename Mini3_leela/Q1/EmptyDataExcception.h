#ifndef EMPTYDATAEXCCEPTION_H
#define EMPTYDATAEXCCEPTION_H

#include <stdexcept>
#include <cstring>

class EmptyDataException : public std::exception
{
private:
    char *_msg;

public:
    EmptyDataException() = delete;
    explicit EmptyDataException(const char *msg)
    {
        _msg = new char[strlen(msg) + 1];
        strcpy(_msg, msg);
    }
    EmptyDataException(const EmptyDataException &) = default;
    EmptyDataException &operator=(const EmptyDataException &) = delete;
    EmptyDataException &operator=(EmptyDataException &&) = delete;
    EmptyDataException(EmptyDataException &&) = default;
    ~EmptyDataException() = default;

    virtual const char *what() { return _msg; }
};


#endif // EMPTYDATAEXCCEPTION_H
