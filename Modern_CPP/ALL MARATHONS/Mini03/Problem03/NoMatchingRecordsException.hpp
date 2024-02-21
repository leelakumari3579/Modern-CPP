#ifndef NOMATCHINGRECORDSEXCEPTION_HPP
#define NOMATCHINGRECORDSEXCEPTION_HPP

#include <stdexcept>
#include <cstring>

class NoMatchingRecordsException : public std::exception {
    private:
        char* _msg;

    public:
        
        // Initial Setup
        NoMatchingRecordsException() = delete;
        NoMatchingRecordsException(const NoMatchingRecordsException&) = delete;
        NoMatchingRecordsException(NoMatchingRecordsException&&) = default;
        NoMatchingRecordsException& operator=(const NoMatchingRecordsException&) = delete;
        NoMatchingRecordsException& operator=(NoMatchingRecordsException&&) = delete;
        ~NoMatchingRecordsException() {
            delete[] _msg;
        };

        // Parameterized Constructors
        explicit NoMatchingRecordsException(const char* msg) {
            _msg = new char[strlen(msg) + 1];
            strcpy(_msg, msg);
        }

        // Overriding what().
        virtual const char* what() { return _msg; };
};

#endif // NOMATCHINGRECORDSEXCEPTION_HPP
