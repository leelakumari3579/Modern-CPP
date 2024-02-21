#ifndef USER_H
#define USER_H

//imports
#include<iostream>


// Class Definition
class User {
    std::string user_id;
    std::string user_name;
    std::string user_department;

    public:
        //Constructors
        User();
        User(std::string, std::string, std::string);

        // Getters and Setters
        std::string getUserId() const { return user_id; }
        void setUserId(const std::string &userId) { user_id = userId; }

        std::string getUserName() const { return user_name; }
        void setUserName(const std::string &userName) { user_name = userName; }

        std::string getUserDepartment() const { return user_department; }
        void setUserDepartment(const std::string &userDepartment) { user_department = userDepartment; }

        // User defined functions
        friend void operator>>(std::istream &, User &);
        bool operator==(const User &);    
        void display();    
};

#endif // USER_H