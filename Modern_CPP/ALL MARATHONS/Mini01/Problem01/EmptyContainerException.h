#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <stdexcept>
#include <cstring>

class EmptyContainerException : public std::exception {
    private:
        char* _msg;

    public:
        
        // Initial Setup
        EmptyContainerException() = delete;
        EmptyContainerException(const EmptyContainerException&) = delete;
        EmptyContainerException(EmptyContainerException&&) = default;
        EmptyContainerException& operator=(const EmptyContainerException&) = delete;
        EmptyContainerException& operator=(EmptyContainerException&&) = delete;
        ~EmptyContainerException() {
            delete _msg;
        };

        // Parameterized Constructors
        explicit EmptyContainerException(const char* msg) {
            _msg = new char[sizeof(msg) + 1];
            strcpy(_msg, msg);
        }

        // Overriding what().
        virtual const char* what() { return _msg; };
};

#endif // EMPTYCONTAINEREXCEPTION_H
