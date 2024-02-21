#include <iostream>

#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsFound.h"

void CreateObjects(LoanContainer &loanData)
{
    loanData.emplace_back(
        std::make_shared<Loan>(1, 22, 59000, LoanType::PERSONAL, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(2, 25, 9600, LoanType::MEDICAL, 5500, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(3, 23, 65500, LoanType::MEDICAL, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(4, 24, 54400, LoanType::MEDICAL, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(5, 21, 9900, LoanType::VENTURE, 2500, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(6, 26, 77100, LoanType::EDUCATION, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(7, 24, 78956, LoanType::MEDICAL, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(8, 24, 83000, LoanType::PERSONAL, 35000, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(9, 21, 10000, LoanType::VENTURE, 1, 16.02, 1)
    );

    loanData.emplace_back(
        std::make_shared<Loan>(10, 22, 85000, LoanType::VENTURE, 35000, 16.02, 1)
    );
}

float AverageLoanAmount(const LoanContainer &loanData)
{
    if(!loanData.empty()) {
        int sum {0}, count {0};
        for(const LoanPointer& lptr : loanData) {
            if(lptr->loanIntent() == LoanType::MEDICAL) {
                sum += lptr->loanAmount();
                count++;
            }
        }
        if(count == 0) {
            throw NoMatchingRecordsFoundException("No loan data matching MEDICAL TYPE found in AverageLoanAmount().");
        }
        return sum / count;
    }
    throw EmptyContainerException("No Loan Data found in the container for AverageLoanAmount().");
}

std::array<int, 4> ValueCount(const LoanContainer &loanData)
{
    if(!loanData.empty()) {
        int ecount {0}, mcount {0}, vcount {0}, pcount {0};
        for(const LoanPointer& lptr : loanData) {
            if(lptr->loanIntent() == LoanType::EDUCATION)   ecount++;
            else if(lptr->loanIntent() == LoanType::MEDICAL)    mcount++;
            else if(lptr->loanIntent() == LoanType::PERSONAL)    pcount++;
            else vcount++;
        }
        return std::array<int, 4> {ecount, pcount, mcount, vcount};
    }
    throw EmptyContainerException("No Loan Data found in the container for ValueCount().");
}

void HighestInterestRateForAcceptedLoans(const LoanContainer &loanData)
{
    if(!loanData.empty()) {
        float maxInterest {0.0f}, tempMax {0.0f};

        for(const LoanPointer& lptr : loanData) {
            tempMax = lptr->loanInterestRate();
            if(tempMax > maxInterest)  maxInterest = tempMax;
        }
        std::cout << "Highest Rate of Interest : " << maxInterest << std::endl;
        return;
    }
    throw EmptyContainerException("No Loan Data found in the container for HighestInterestRateForAcceptedLoans().");
}

void MinMaxAge(const LoanContainer &loanData)
{
    if(!loanData.empty()) {
        int maxAge {0}, minAge {999}, tempAge {0};

        for(const LoanPointer& lptr : loanData) {
            tempAge = lptr->personAge();
            if(tempAge > maxAge)    maxAge = tempAge;
            if(tempAge < minAge)    minAge = tempAge;
        }
        std::cout << "Max Age: " << maxAge << std::endl;
        std::cout << "Min Age: " << minAge << std::endl;
        return;
    }
    throw EmptyContainerException("No Loan Data found in the container for HighestInterestRateForAcceptedLoans().");
}

std::vector<Loan> GetLoanApplications(const LoanContainer &loanData)
{
    if(!loanData.empty()) {
        std::vector<Loan> loans;
        float tempLoanAmt;
        for(const LoanPointer& lptr : loanData) {
            tempLoanAmt = lptr->loanAmount();
            if((tempLoanAmt >= 20000 && tempLoanAmt <= 40000) && (lptr->loanStatus() == 1) && (lptr->personAge() > 23)) {
                loans.emplace_back(*lptr);
            }
        }
        if(loans.empty()) {
            throw NoMatchingRecordsFoundException("No loan data matching found in GetLoanApplications().");
        }
        return loans;
    }
    throw EmptyContainerException("No Loan Data found in the container for HighestInterestRateForAcceptedLoans().");    
}

float GetMaxLoanInterestRateByIntent(const LoanContainer &loanData, LoanType loanIntent)
{
    if(!loanData.empty()) {
        float maxLoanInterest {0.0f}, tempInt {0.0};
        for(const LoanPointer& lptr : loanData) {
            tempInt = lptr->loanInterestRate();
            if(lptr->loanIntent() == loanIntent && tempInt > maxLoanInterest) {
                maxLoanInterest = tempInt;
            }
        }
        return maxLoanInterest;
    }
    throw EmptyContainerException("No Loan Data found in the container for HighestInterestRateForAcceptedLoans().");    
}
