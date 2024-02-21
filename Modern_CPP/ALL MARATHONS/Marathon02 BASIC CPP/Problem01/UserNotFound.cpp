#include <cstring>
#include "UserNotFound.h"

// Constructor definitions
UserNotFoundException::UserNotFoundException(): message("Users not found") {}

UserNotFoundException::UserNotFoundException(const std::string message) {
    this->message = message;
}

std::string UserNotFoundException::what() {
    return message;
}