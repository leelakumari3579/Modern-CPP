#include "header.h"
#include <iostream>
#include <cstring>
#include <string>
using namespace std;
void Loan::insertRecord(char *n)
{
    long int lN;
    float a;
    float iA;

    cout<<"Enter loan Number : ";
    cin>>lN;
    this->loanNumber=lN;

    strcpy(this->name, n);

    cout<<endl<<"Enter amount : ";
    cin>>a;
    this->amount=a;
}

void Loan ::PrintRecord()
{
    cout << "The Loan No. :  " << this->loanNumber << endl;
    cout << "The Loan Amount : " << this->amount << endl;
    cout << "Account Holder Name : " << this->name << endl;
    cout << "The interest amount : " << this->interestAmount << endl;
}

float Loan ::calculateInterest(float amount)
{
    float interest;
    if (amount <= 100000)
        this->interestAmount = (double)0.02 * amount;

    else if (amount > 100000 && amount <= 500000)
        this->interestAmount = (double)0.05 * amount;

    else if (amount > 500000 && amount <= 1500000)
        this->interestAmount = (double)0.1 * amount;

    interest = this->interestAmount;
    return interest;
}