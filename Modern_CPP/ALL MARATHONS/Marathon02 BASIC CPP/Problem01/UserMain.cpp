#include <iostream>
#include "User.h"
#include "UserNotFound.h"

// Globlal Function
int countSameDepratment(User users[], std::string departmentName) {
    int count=0;
    for(int i=0; i<3; i++) {
        if(users[i].getUserDepartment() == departmentName) {
            users[i].display();
            count++;
        }
    }
    if(count == 0)
        throw UserNotFoundException("No user found in department "+departmentName);
    return count;

}

// Driver Code
int main() {
    std::string departmentName;
    User users[3];
    for(int i=0; i<3; i++) {
        std::cin>>users[i];
    }

    std::cout<<"Please enter the department name you wan to search: ";
    std::cin>>departmentName;

    
    try {
        int sameDepartmentCount = countSameDepratment(users, departmentName);
        std::cout<<"\nFound "<<sameDepartmentCount<<" Users in Department"<<departmentName<<std::endl;
    }
    catch(UserNotFoundException e) {
        std::cout<<e.what()<<std::endl;
    }

    User u1("KPIT219301", "Kartik", "CPP");
    User u2("KPIT219237", "Aarti", "EMBEDDED");
    User u3("KPIT2192307", "Kaaku", "MBD");

    bool r1 = u1 == u2;
    bool r2 = u2 == u3;

    std::cout<<" User 1 == User2 ?: "<<r1<<std::endl;
    std::cout<<" User 2 == User3 ?: "<<r2<<std::endl;
}