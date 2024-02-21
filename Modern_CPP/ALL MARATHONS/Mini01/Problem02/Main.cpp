#include <iostream>
#include "Functionalities.h"
#include "EmptyContainerException.h"
#include "NoMatchingRecordsFound.h"

int main() {
    LoanContainer loanData;
    float fresult {0.0f};
    CreateObjects(loanData);

    try {
        std::cout << "Calculating Average Loan Amount..." << std::endl;
        fresult = AverageLoanAmount(loanData);
        std::cout << "Average Loan Amount: " << fresult << std::endl;
    } catch(NoMatchingRecordsFoundException& ex) {
        std::cout <<ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Counting number of loan categories..." << std::endl;
        std::array<int, 4> counts = ValueCount(loanData);
        std::cout << "EDUCATION: " << counts[0] << std::endl;
        std::cout << "PERSONAL: " << counts[1] << std::endl;
        std::cout << "MEDICAL: " << counts[2] << std::endl;
        std::cout << "VENTURE: " << counts[3] << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Calculating highest interest rate for accepted loans..." << std::endl;
        HighestInterestRateForAcceptedLoans(loanData);
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Checking for Highest and lowest Age of Loan Applicants..." << std::endl;
        MinMaxAge(loanData);
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Getting Loan Applications with specified conditions." << std::endl;
        std::vector<Loan> loans = GetLoanApplications(loanData);
        for(const Loan& lptr : loans) {
            std::cout << lptr << std::endl;
        }
    } catch(NoMatchingRecordsFoundException& ex) {
        std::cout <<ex.what() << std::endl;
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    try {
        std::cout << "Checking for Maximum Loan Interest Rate Based on Loan Intent MEDICAL..." << std::endl;
        fresult = GetMaxLoanInterestRateByIntent(loanData, LoanType::MEDICAL);
    } catch(EmptyContainerException& ex) {
        std::cout <<ex.what() << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Thanks for using the system!!" << std::endl;
}