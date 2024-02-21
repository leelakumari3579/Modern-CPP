#include "Functionalities.h"
#include "AccountType.h"

void CreateObjects(AccountContainer& accounts, MapContainer &data)
{
    accounts.emplace_back(std::make_shared<BankAccount> (
            "harsh",
            AccountType::CURRENT, 
            780000.0f,
            std::make_shared<DebitCard>(
                111,
                2123678689678l,
                "09/24",
                DebitCardType::RUPAY
            )
        )
    );

    accounts.emplace_back(std::make_shared<BankAccount> (
            "nani",
            AccountType::SAVINGS, 
            1080000.0f,
            std::make_shared<DebitCard>(
                123,
                2145678678l,
                "10/25",
                DebitCardType::MASTERCARD
            )
        )
    );

    accounts.emplace_back(std::make_shared<BankAccount> (
            "venkat",
            AccountType::PENTION, 
            1000000.0f,
            std::make_shared<DebitCard>(
                221,
                21230987678l,
                "09/27",
                DebitCardType::VISA
            )
        )
    );

    data.emplace(
        std::make_pair<unsigned long, Accountpointer>(
            accounts[0]->_accounaccountNumber(), std::move(accounts[0])
        )
    );

    data.emplace(
        std::make_pair<unsigned long, Accountpointer>(
            accounts[1]->_accounaccountNumber(), std::move(accounts[1])
        )
    );

    data.emplace(
        std::make_pair<unsigned long, Accountpointer>(
            accounts[2]->_accounaccountNumber(), std::move(accounts[2])
        )
    );
}

float FindBankBalance(const MapContainer &data)
{
    if(data.empty())
        std::runtime_error("data not avilable");
    
    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float total, std::pair<unsigned long, Accountpointer>&& p) {
            return total + p.second->accountBalance();
        }
    );
    return ans;
}

unsigned int CountAbove50000BalanaceAccounts(const MapContainer &data)
{
    if(data.empty())
        std::runtime_error("data not avilable");

    std::size_t count =  std::count_if(
        data.begin(),
        data.end(),
        [](std::pair<unsigned long, Accountpointer>&& p) {
            return p.second->accountBalance() > 50000.0f;
        }
    );
    return count;
}

bool IsAnyAccountWithNoCard(const MapContainer &data)
{
    if(data.empty())
        std::runtime_error("data not avilable");

    bool ans =  std::any_of(
        data.begin(),
        data.end(),
        [](std::pair<unsigned long, Accountpointer>&& p) {
            return p.second->accountDebitCard() == nullptr;
        }
    );
    return ans;
}

std::optional<float> FindBalanceById(const MapContainer &data, unsigned long accNumber)
{
    if(data.empty())
        std::runtime_error("data not avilable");

    auto itr = std::find_if(
        data.begin(),
        data.end(),
        [&](std::pair<unsigned long, Accountpointer>&& p) {
            return p.second->_accounaccountNumber() == accNumber;
        }
    );

    if(itr == data.end())
        return std::nullopt;
    
    return (*itr).second->accountBalance();
}

// Unorderd Map<key, value>   --->create a key, create an object 
//                                => move them into a pair, pair moves into hashtable
// step1 : create an object. preserve its lifetime in some sort of data container( not hashtable)