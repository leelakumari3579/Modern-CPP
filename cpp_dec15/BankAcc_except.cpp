#include <iostream>
#include<cstring>
//user defined exception class 
class BalInsufficientException:public std::exception
{
    char message[100];
    public:
        BalInsufficientException()
        {
            strcpy(message,"Insufficient Balance ");
        }
         BalInsufficientException(const char *s)
        {
            strcpy(message,s);
        }
        char * what()
        {
            return message;
        }
};

class BankAccount
{
    private:
        float amnt;
    public:
        BankAccount();
        BankAccount(int);
        int Debit(int);
        int Credit(int);
        int FetchBal();
};

BankAccount::BankAccount()
{
    amnt=5000;
}

BankAccount::BankAccount(int amt)
{
    amnt=amt;
}

int BankAccount::Debit(int amt)
{
    if(amnt<=5000 || amnt-amt<=5000)
        throw BalInsufficientException("minimum balance 5000 required ");
    amnt -=amt;
    return amnt;
}

int BankAccount::Credit(int amt)
{
    amnt +=amt;
    return amnt;
}

int BankAccount::FetchBal()
{
    return amnt;
}

int main()
{
    BankAccount b;
    try
    {
        std::cout<<"remaoining amount after debited "<<b.Debit(3000)<<std::endl;
    }
    catch ( BalInsufficientException obj)
    {
        std::cout <<"\n"<< obj.what() << "\n";
    }
    catch(std::exception  e )// generic handler
    {
        std::cout<<e.what();
    }
    std::cout<<"remaining amount after credited"<<b.Credit(4000)<<std::endl;
    std::cout<<"total amount"<<b.FetchBal();
}