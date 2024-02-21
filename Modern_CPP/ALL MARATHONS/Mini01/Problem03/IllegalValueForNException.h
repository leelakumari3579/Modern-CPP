#ifndef ILLEGALVALUEFORNEXCEPTION_H
#define ILLEGALVALUEFORNEXCEPTION_H

#include <stdexcept>
#include <cstring>

class IllegalValueForNException : public std::exception {

    private:
        char* _msg;

    public:
        
        // Initial Setup
        IllegalValueForNException() = delete;
        IllegalValueForNException(const IllegalValueForNException&) = delete;
        IllegalValueForNException(IllegalValueForNException&&) = default;
        IllegalValueForNException& operator=(const IllegalValueForNException&) = delete;
        IllegalValueForNException& operator=(IllegalValueForNException&&) = delete;
        ~IllegalValueForNException() {
            delete _msg;
        };

        // Parameterized Constructors
        explicit IllegalValueForNException(const char* msg) {
            _msg = new char[sizeof(msg) + 1];
            strcpy(_msg, msg);
        }

        // Overriding what().
        virtual const char* what() { return _msg; };
};

#endif // ILLEGALVALUEFORNEXCEPTION_H
