#ifndef HEADER_H
#define HEADER_H
#include<cstring>
class Loan
{
    // private:
        long int loanNumber;
        float Amount;
        char Name[30];
        float interestAmount;
    public:
        Loan();
        Loan(long int,float,char[],float);
        ~Loan();

        long int getLoanNumber() { return loanNumber; }
        void setLoanNumber(long int loanNumber_) { loanNumber = loanNumber_; }

        float amount() { return Amount; }
        void setAmount(float amount) { Amount = amount; }

        char *name() { return Name; }
        void setName(char *name) { strcpy(Name,name); }

        float getInterestAmount() { return interestAmount; }
        void setInterestAmount(float interestAmount_) { interestAmount = interestAmount_; }

        void CalculateInterest();
        void InserRecord();
        void PrintRecord();

        // void Add(int,int);
};

#endif // HEADER_H
