#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <vector>
#include <optional>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<AccountPointer>;
using CardPointer = std::shared_ptr<DebitCard>;
using CardContainer = std::vector<CardPointer>;

void CreateObject(Container& data); //empty

//return the total bank balance from all accounts
float FindBankBalance(const Container& data);

//return count of accounts , balance above 50000
unsigned int CountAbove50000BalanaceAccounts(const Container& data);

bool IsAnyAccountWithNoCard(const Container& data);

unsigned short FindMaxBalanaceCvvNumber(const Container& data);

/*
    return the expiry date of the bedit card attached with the amount with min balance
    of multiple such min accounts exist, return the first match found
*/
std::string FindMinBalanceExpiry(const Container& data);

//return all shared pointers to debitcard instafrom all accounts
CardContainer ReturnDebitCardPointers(const Container& data);

//return non-null debitcard pointers ina container from all accounts
std::optional<CardContainer> ReturnNoNullDebitCardPointers(const Container& data);

/*
    return a container of shared pointer to account objcts if 
        a) account has a balance of over 30000
        b) account debit card is not null
*/
std::optional<Container> FindMatchingAccounts(const Container& data);

#endif // FUNCTIONALITIES_H

