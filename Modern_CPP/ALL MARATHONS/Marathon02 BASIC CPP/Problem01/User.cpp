#include <iostream>
#include <cstring>
#include "User.h"

// Constructor Definitions
User::User(): user_name("Anonymous"), user_id("NIL"), user_department("NA") {}

User::User(std::string user_id, std::string user_name, std::string user_department):
user_id{user_id}, user_name{user_name}, user_department{user_department} {}

// Operator >> overloading
void operator>>(std::istream &in, User &u) {
    std::string name;
    std::cout<<"Enter the ID of the user: ";
    in>>u.user_id;

    std::cout<<"Enter the name of the user: ";
    in>>u.user_name;

    std::cout<<"Enter the department of the user: ";
    in>>u.user_department;

    std::cout<<"Record Added Successfully."<<std::endl;
}

// Operator == overloading
bool User::operator==(const User &u) {
    return this->getUserDepartment() == u.getUserDepartment();
}

// Display definition
void User::display() {
    std::cout<<"User ID: "<<user_id<<" User Name: "<<user_name<<" User Department: "<<user_department<<std::endl;
}