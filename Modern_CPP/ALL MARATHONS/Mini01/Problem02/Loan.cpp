#include "Loan.h"

Loan::Loan(int id, int personAge, float personIncome, LoanType loanIntent, float loanAmount, float loanInterestRate, int loanStatus):
_id(id), _personAge(personAge), _personIncome(personIncome), _loanIntent(loanIntent), _loanAmount(loanAmount),
_loanInterestRate(loanInterestRate), _loanStatus(loanStatus) {}
std::ostream &operator<<(std::ostream &os, const Loan &rhs) {
    os << "_id: " << rhs._id
       << " _personAge: " << rhs._personAge
       << " _personIncome: " << rhs._personIncome
       << " _loanIntent: " << static_cast<int>(rhs._loanIntent)
       << " _loanAmount: " << rhs._loanAmount
       << " _loanInterestRate: " << rhs._loanInterestRate
       << " _loanStatus: " << rhs._loanStatus;
    return os;
}
