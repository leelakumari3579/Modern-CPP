#ifndef LOAN_H
#define LOAN_H

#include "LoanType.h"
#include <ostream>

class Loan {
    
    private:
    
        const int _id;
        int _personAge;
        float _personIncome;
        LoanType _loanIntent;
        float _loanAmount;
        float _loanInterestRate;
        int _loanStatus;

    public:

        //Initial Setup
        Loan() = delete;
        Loan(const Loan&) = default;
        Loan(Loan&&) = delete;
        Loan& operator=(const Loan&) = delete;
        Loan& operator=(Loan&&) = delete;
        ~Loan() = default;

        //Parameterized Constructor
        Loan(int id, int personAge, float personIncome, LoanType loanIntent, float loanAmount, float loanInterestRate, int loanStatus);

        
        // Getters
        int id() const { return _id; }
        int personAge() const { return _personAge; }
        float personIncome() const { return _personIncome; }
        LoanType loanIntent() const { return _loanIntent; }
        float loanAmount() const { return _loanAmount; }
        float loanInterestRate() const { return _loanInterestRate; }
        int loanStatus() const { return _loanStatus; }

        friend std::ostream &operator<<(std::ostream &os, const Loan &rhs);
};

#endif // LOAN_H
