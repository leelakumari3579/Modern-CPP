#include "BankAccount.h"
#include <limits>
#include <stdexcept>

//use exceptions would be better

void BankAccount::DepositAmount(long amount)
{
    if(_accountBalance + amount > __LONG_MAX__)
    {
        throw std::runtime_error("cannot deposit an amount this large!");
    }
    _accountBalance += amount;
}
void BankAccount::WithdrawAmount(long amount)
{
    if(amount > _accountBalance)
    {
        throw std::runtime_error("cannot withdaw amount this large!");
    }
    _accountBalance -= amount;
}

BankAccount::BankAccount(const long accNo,std::string accountHolderName, AccountType accountType, float accountBalance)
    :_accountNumber(++_counter),_accountHolderName(accountHolderName), _accountType(accountType), _accountBalance(accountBalance)
{
}

BankAccount::BankAccount(const long accNo,std::string accountHolderName, AccountType accountType, float accountBalance, CardPointer accountDebitCard)
    : BankAccount(accNo,accountHolderName, accountType, accountBalance)
{
    _accountDebitCard = accountDebitCard;
}
