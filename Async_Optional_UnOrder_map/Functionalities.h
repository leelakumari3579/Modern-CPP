#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <unordered_map>
#include <optional>
#include <algorithm>
#include <numeric>
#include <memory>
#include <vector>
#include "BankAccount.h"

using Accountpointer = std::shared_ptr <BankAccount>;
using MapContainer = std::unordered_map<unsigned long, Accountpointer>;
using AccountContainer = std::vector<Accountpointer>;

void CreateObjects(AccountContainer& accounts, MapContainer& data);

//return the total bank balance from all accounts
float FindBankBalance(const MapContainer& data);

//return count of accounts , balance above 50000
unsigned int CountAbove50000BalanaceAccounts(const MapContainer& data);

bool IsAnyAccountWithNoCard(const MapContainer& data);

//find the account nalance of the account whose account number is provided as a parameter
std::optional<float> FindBalanceById(const MapContainer& data, unsigned long accNumber);


#endif // FUNCTIONALITIES_H
