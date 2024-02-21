#ifndef ILLEGALVALUEEXCEPTION_HPP
#define ILLEGALVALUEEXCEPTION_HPP

#include <stdexcept>
#include <cstring>

class IllegalValueException : public std::exception {
    private:
        char* _msg;

    public:
        
        // Initial Setup
        IllegalValueException() = delete;
        IllegalValueException(const IllegalValueException&) = delete;
        IllegalValueException(IllegalValueException&&) = default;
        IllegalValueException& operator=(const IllegalValueException&) = delete;
        IllegalValueException& operator=(IllegalValueException&&) = delete;
        ~IllegalValueException() {
            delete[] _msg;
        };

        // Parameterized Constructors
        explicit IllegalValueException(const char* msg) {
            _msg = new char[strlen(msg) + 1];
            strcpy(_msg, msg);
        }

        // Overriding what().
        virtual const char* what() { return _msg; };
};

#endif // ILLEGALVALUEEXCEPTION_HPP
