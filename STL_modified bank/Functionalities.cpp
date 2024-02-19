#include "Functionalities.h"
#include <algorithm>
#include <numeric>

void CreateObject(Container &data)
{
    data.push_back(
        std::make_shared<BankAccount>(
            "harshit",            //name
            AccountType::SAVINGS, //account type
            898128478.0f,         //balance
            //Debit card
            std::make_shared<DebitCard>(
                111,
                1123353211L,
                "12/27",
                DebitCardType::VISA
            )
        )
    );

    data.push_back(
        std::make_shared<BankAccount>(
            "rohan",              //name
            AccountType::CURRENT, //account type
            345235468.0f,         //balance
            //Debit card
            std::make_shared<DebitCard>(
                22,
                4135453211L,
                "12/28",
                DebitCardType::RUPAY
            )
        )
    );
}

float FindBankBalance(const Container & data)
{
    if(data.empty())
        std::runtime_error("no data found!!");
   
    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [](float total, const AccountPointer& ptr) {
            return total + ptr->accountBalance();
        }
    );
    return ans;
}

unsigned int CountAbove50000BalanaceAccounts(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    //size_t ---> unsigned long integer(numeric type)
    //we can also use int or .... in place of size_t ---gives same ans
    size_t ans = std::count_if(
        data.begin(),
        data.end(),
        [](const AccountPointer& ptr) {
            return ptr->accountBalance()>50000.0f;
        }
    );
    return ans; 
}

bool IsAnyAccountWithNoCard(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    bool ans = std::any_of(
        data.begin(),
        data.end(),
        [](const AccountPointer& ptr) {
            return ptr->accountDebitCard() == nullptr;
        }
    );
    return ans; 
}

unsigned short FindMaxBalanaceCvvNumber(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    auto itr = std::max_element(
        data.begin(),
        data.end(),
        [](const AccountPointer& ptr1, const AccountPointer& ptr2) {
            return ptr1->accountBalance() > ptr2->accountBalance();
        }
    );
    return (*itr)->accountDebitCard()->cvv();
}

std::string FindMinBalanceExpiry(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    auto itr = std::min_element(
        data.begin(),
        data.end(),
        [](const AccountPointer& ptr1, const AccountPointer& ptr2) {
            return ptr1->accountBalance() < ptr2->accountBalance();
        }
    );
    return (*itr)->accountDebitCard()->expiryDate();
}

CardContainer ReturnDebitCardPointers(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    Container temp(data.size());
    CardContainer result;

    std::copy(
        data.begin(),
        data.end(),
        result.begin()
    );

    std::for_each(
        temp.begin(),
        temp.end(),
        [&](const AccountPointer& ptr) {
            result.push_back(ptr->accountDebitCard());
        }
    );

    return result;
}

/*
    step1: for all accounts where condition matches, copy the whole account into a top container
    step2: from the temp cotainer, extract the debitcard and replace and place in the result container
    step3: 
*/
std::optional<CardContainer> ReturnNoNullDebitCardPointers(const Container &data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    Container temp(data.size());
    CardContainer result;

    std::copy_if(
        data.begin(),
        data.end(),
        temp.begin(),
        [](const AccountPointer& ptr) {
           return ptr->accountDebitCard() != nullptr;
        }
    );

    std::for_each(
        temp.begin(),
        temp.end(),
        [&](const AccountPointer& ptr) {
            result.push_back(ptr->accountDebitCard());
        }
    );

    if(result.empty())
        std::nullopt;

    return result;

    // //Alternate solution
    // std::for_each(
    //     data.begin(),
    //     data.end(),
    //     [](const AccountPointer& ptr) {
    //         if(ptr->accountDebitCard() != nullptr)
    //         {
    //             result.push_back(ptr->accountDebitCard());
    //         }
    //     }
    // );
}

//when ever we use copy items we use just std::copy
//when we want copy specific objects , we have to change the process

std::optional<Container> FindMatchingAccounts(const Container & data)
{
    if(data.empty())
        std::runtime_error("no data found!!");

    Container result(data.size());

    //copy_if return the iterator to the last copied element
    auto itr = std::copy_if(
        data.begin(),
        data.end(),
        result.begin(),
        [](const AccountPointer& ptr) {
            return ptr->accountBalance() > 30000 && ptr->accountDebitCard() != nullptr;
        }
    );

    std::size_t newSize = std::distance(result.begin(), itr);
    result.resize(newSize);

    if(result.empty())
        std::nullopt;

    return result;
}


