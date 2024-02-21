#ifndef LOAN_H
#define LOAN_H
#include<cstring>
class Loan{
    private:
        int loanNo;
        float amount;
        char name[20];
        float interestAmount;

    public:
        static int cnt;
        Loan();
        Loan(int amt,char n[],float rate);
        void insertRecord();
        void printRecord();
        void calculateInterest();
        int getLoanNo() const { return loanNo; }
        void setLoanNo(int loanNo_) { loanNo = loanNo_; }

        float getAmount() const { return amount; }
        void setAmount(float amount_) { amount = amount_; }

        float getInterestNo() const { return interestAmount; }
        void setInterestNo(float interestNo_) { interestAmount = interestNo_; }

        const char* getName() const { return name; }
        void setName(char* name_) {strcpy( name,name_); }

        // const char* getName() const { return name; }
        // void setName(const char* name_) { strcpy(name,name_); }
    
};

// global functions;
// void Add(Loan );
// void Show(Loan );
// void Search();
// void CountCustomers();

#endif // LOAN_H
