#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <memory>
#include <vector>

#include "Loan.h"

using LoanPointer = std::shared_ptr<Loan>;
using LoanContainer = std::vector<LoanPointer>;

void CreateObjects(LoanContainer& loanData);

float AverageLoanAmount(const LoanContainer& loanData);

std::array<int, 4> ValueCount(const LoanContainer& loanData);

void HighestInterestRateForAcceptedLoans(const LoanContainer& loanData);

void MinMaxAge(const LoanContainer& loanData);

std::vector<Loan> GetLoanApplications(const LoanContainer& loanData);

float GetMaxLoanInterestRateByIntent(const LoanContainer& loanData, LoanType loanIntent);

#endif // FUNCTIONALITIES_H
