#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<cstring>

class LoanManagementSystem {
    int loanNumber;
    float loanAmount;
    char name[50];
    float loanInterestAmount;

    public:

        // Default Constructor Declaration
        LoanManagementSystem();

        // Parameterized Constructor Declaration
        LoanManagementSystem(int, float, const char *);


        // Getters and Setters of Data Members
        int getLoanNumber() const { return loanNumber; }
        void setLoanNumber(int loanNumber_) { loanNumber = loanNumber_; }

        float getLoanAmount() const { return loanAmount; }
        void setLoanAmount(float loanAmount_) { loanAmount = loanAmount_; }

        char* getName() { return name; }
        void setName(char *name_) { strcpy(name, name_); }

        float getLoanInterestAmount() const { return loanInterestAmount; }
        void setLoanInterestAmount(float loanInterestAmount_) { loanInterestAmount = loanInterestAmount_; }

        // User Defined Methods Declaration.

        void calculateInterest();
        void insertRecord();
        void printRecord();

};

#endif // HEADER_H
