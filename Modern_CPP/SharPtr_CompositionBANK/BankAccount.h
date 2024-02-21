#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <string>
#include <memory>
#include "AccountType.h"
#include "DebitCard.h"

using CardPointer = std::shared_ptr<DebitCard>;

class BankAccount
{
private:
    static int _counter;
    const unsigned long _accountNumber;
    std::string _accountHolderName;
    AccountType _accountType;
    float _accountBalance;
    CardPointer _accountDebitCard;

public:
    //special member funtion enable/desable
    BankAccount() = delete;
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;
    BankAccount(BankAccount&&) = delete;
    BankAccount& operator=(BankAccount&&) = delete;
    ~BankAccount() = default;

    //member function for account behaviour
    void DepositAmount(long amount);
    void WithdrawAmount(long amount);

    BankAccount(const long accNo, std::string accountHolderName, AccountType accountType, float accountBalance);
    BankAccount(const long accNo,std::string accountHolderName, AccountType accountType, float accountBalance, CardPointer accountDebitCard);

    //getters and setters for member access
    unsigned long _accounaccountNumber() const { return _accountNumber; }
    std::string accountHolderName() const { return _accountHolderName; }
    void setAccountHolderName(const std::string &accountHolderName) { _accountHolderName = accountHolderName; }
    AccountType accountType() const { return _accountType; }
    CardPointer accountDebitCard() const { return _accountDebitCard; }
    void setAccountType(const AccountType &accountType) { _accountType = accountType; }

    float accountBalance() const { return _accountBalance; }
    void setAccountBalance(float accountBalance) { _accountBalance = accountBalance; }

};

inline int BankAccount::_counter = 900000;

#endif // BANKACCOUNT_H
