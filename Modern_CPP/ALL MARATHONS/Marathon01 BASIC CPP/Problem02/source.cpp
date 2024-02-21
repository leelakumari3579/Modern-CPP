#include<iostream>
#include<cstring>
#include "header.h"

// Default Constructor Definition
LoanManagementSystem::LoanManagementSystem() {
    loanNumber = 0;
    loanAmount = 0.0f;
    strcpy(name, "Not Available");
    loanInterestAmount = 0.0;
}

// Parameterized Constructor Definition
LoanManagementSystem::LoanManagementSystem(int ln, float amnt, const char *name)
:loanNumber(ln), loanAmount(amnt) {
    strcpy(this->name, name);
    calculateInterest();
}

// Calculate Interest Definition.
void LoanManagementSystem::calculateInterest() {
    if(loanAmount <= 100000)
        loanInterestAmount = 0.02 * loanAmount;
    else if(loanAmount > 100000 && loanAmount <= 500000)
        loanInterestAmount = 0.05 * loanAmount;
    else if(loanAmount > 500000 && loanAmount <1500000)
        loanAmount = 0.1 * loanAmount;
}

// Inserting Record Definition
void LoanManagementSystem::insertRecord() {
    std::cout<<"Enter the loan number: ";
    std::cin>>loanNumber;

    std::cout<<"Enter the loan amount: ";
    std::cin>>loanAmount;

    std::cout<<"Enter the name: ";
    std::cin>>name;

    calculateInterest();

    std::cout<<"\n\n\t\t***Record Inserted Successfully***\n"<<std::endl;
}

// Printing Record Definition
void LoanManagementSystem::printRecord() {
    std::cout<<"Loan Number: "<<loanNumber<<std::endl;
    std::cout<<"Loan Amount: "<<loanAmount<<std::endl;
    std::cout<<"Name of holder: "<<name<<std::endl;
    std::cout<<"Interest Amount on Loan: "<<loanInterestAmount<<std::endl;
    std::cout<<std::endl;
}