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

BankAccount::BankAccount(std::string accountHolderName, AccountType accountType, float accountBalance)
    :_accountNumber(++_counter), _accountType(accountType), _accountBalance(accountBalance)
{
}

BankAccount::BankAccount(std::string accountHolderName, AccountType accountType, float accountBalance, CardPointer accountDebitCard)
    : BankAccount(accountHolderName, accountType, accountBalance)
{
    _accountDebitCard = accountDebitCard;
}
