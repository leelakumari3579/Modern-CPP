#ifndef NOMATCHINGRECORDSFOUND_H
#define NOMATCHINGRECORDSFOUND_H

#include <stdexcept>
#include <cstring>

class NoMatchingRecordsFoundException : public std::exception {

    private:
        char* _msg;

    public:
        
        // Initial Setup
        NoMatchingRecordsFoundException() = delete;
        NoMatchingRecordsFoundException(const NoMatchingRecordsFoundException&) = delete;
        NoMatchingRecordsFoundException(NoMatchingRecordsFoundException&&) = default;
        NoMatchingRecordsFoundException& operator=(const NoMatchingRecordsFoundException&) = delete;
        NoMatchingRecordsFoundException& operator=(NoMatchingRecordsFoundException&&) = delete;
        ~NoMatchingRecordsFoundException() {
            delete _msg;
        };

        // Parameterized Constructors
        explicit NoMatchingRecordsFoundException(const char* msg) {
            _msg = new char[sizeof(msg) + 1];
            strcpy(_msg, msg);
        }

        // Overriding what().
        virtual const char* what() { return _msg; };
};

#endif // NOMATCHINGRECORDSFOUND_H
