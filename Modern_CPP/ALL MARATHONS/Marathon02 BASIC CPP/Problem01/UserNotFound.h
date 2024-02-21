#ifndef USERNOTFOUND_H
#define USERNOTFOUND_H

#include<iostream>


// User Defined Exception
class UserNotFoundException: public std::exception {
    std::string message;

    public:

    UserNotFoundException();
    UserNotFoundException(const std::string);
    std::string what();
};

#endif // USERNOTFOUND_H
