#include<iostream>
#include<cstring>
#include "header.h"

// Adding a single record.
void add1Record(LoanManagementSystem *lms, int index) {
    lms[index].insertRecord();
    std::cout<<"----------------------------------------------------"<<std::endl;
}

// Displaying records.
void displayRecords(LoanManagementSystem *lms, int size) {
    for(int i=0; i<size; i++) {
        lms[i].printRecord();
    }
    std::cout<<std::endl;
    std::cout<<"----------------------------------------------------"<<std::endl;
}

// Searching for a record.
void searchRecords(LoanManagementSystem *lms, int size) {
    int idToBeSearched, flag=0;
    std::cout<<"Enter the ID of the loan you want to search: ";
    std::cin>>idToBeSearched;
    for(int i=0; i<size; i++) {
        if(lms[i].getLoanNumber() == idToBeSearched) {
            std::cout<<"\n\n\t\t***Record Found!!!***\n\n"<<std::endl;
            lms[i].printRecord();
            flag=1;
            break;
        }
    }
    if(flag == 0) {
        std::cout<<"\n\n\t\t***Error: No record found against entered ID.***\n\n"<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"----------------------------------------------------"<<std::endl;
}

// Finding who has highest interest amount.
void searchHighestInterest(LoanManagementSystem *lms, int size) {
    int max=lms[0].getLoanInterestAmount(), index=0, interestAmount;
    for(int i=1; i<size; i++) {
        interestAmount = lms[i].getLoanInterestAmount();
        if( interestAmount > max) {
            max=interestAmount;
            index = i;
        }
    }
    std::cout<<"Loan with highest interest amount: "<<std::endl<<std::endl;
    lms[index].printRecord();
    std::cout<<std::endl;
    std::cout<<"----------------------------------------------------"<<std::endl;
}

// Driver Code
int main() {

    int numberOfLoans, option=0, count=0;
    
    // User Input Section for number of Loan objects to be created.
    std::cout<<"Enter the number of Loan Data to be recorded: ";
    std::cin>>numberOfLoans;

    // Creating 'numberOfLoans' Loan objects dynamically, hence on heap.
    LoanManagementSystem *lms = new LoanManagementSystem[numberOfLoans];

    // Start of Manu-Driven Logic.
    while(1) {
        std::cout<<"Enter the options for a transaction: "<<std::endl<<std::endl;

        std::cout<<"Enter 1 for Adding a record in the database."<<std::endl;
        std::cout<<"Enter 2 for displaying records stored."<<std::endl;
        std::cout<<"Enter 3 for searcing a particular record."<<std::endl;
        std::cout<<"Enter 4 to check for highest loan interest amount."<<std::endl;
        std::cout<<"Enter 5 if you are done with the transactions."<<std::endl;
        std::cout<<"> ";

        std::cin>>option;

        switch(option) {
            case 1: add1Record(lms, count++);
                    break;

            case 2: displayRecords(lms, numberOfLoans);
                    break;

            case 3: searchRecords(lms, numberOfLoans);
                    break;

            case 4: searchHighestInterest(lms, numberOfLoans);
                    break;

            case 5: std::cout<<"Thank for using the system.\n\n";
                    exit(0);

            default: std::cout<<"\n\n\t\t***Please enter a valid option.***\n\n";
                    break;
        }
    }
} // main end.