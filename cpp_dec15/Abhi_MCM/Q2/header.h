#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <string>
class Loan
{
private:
    long int loanNumber;
    float amount;
    char name[50];
    float interestAmount;

public:
    Loan()
    {
        loanNumber = 0;
        amount = 0.0;
        strcpy(name, "xxx");
        interestAmount = 0.0;
    }

    Loan(long int lN, float a, char *n, float iA) : loanNumber(lN), amount(a), interestAmount(iA)
    {
        strcpy(name, n);
    }

    long int getLoanNumber() const { return loanNumber; }
    void setLoanNumber(long int loanNumber_) { loanNumber = loanNumber_; }

    float getAmount() const { return amount; }
    void setAmount(float amount_) { amount = amount_; }

    char *getName() { return name; }
    void setName(char *name_) { strcpy(name, name_); }

    float getInterestAmount() const { return interestAmount; }
    void setInterestAmount(float interestAmount_) { interestAmount = interestAmount_; }


    float calculateInterest(float loanAmount);
    void insertRecord(char *n);
    void PrintRecord();
};

#endif // HEADER_H