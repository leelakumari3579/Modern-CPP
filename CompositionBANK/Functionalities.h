#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include <vector>
#include "BankAccount.h"

using AccountPointer = std::shared_ptr<BankAccount>;
using Container = std::vector<AccountPointer>;

void CreateObject(Container& data); //empty
void Print(Container& data);

#endif // FUNCTIONALITIES_H
