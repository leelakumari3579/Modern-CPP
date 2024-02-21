#include "Functionalities.h"
#include <numeric>
#include <algorithm>

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

float FindAverageBalance(Container & data)
{
    int count = 0;
    float ans = std::accumulate(
        data.begin(),
        data.end(),
        0.0f,
        [&](int val,AccountPointer& ptr){
            count++;
            return val + ptr->accountBalance();
        }
    );
    return ans/count;
}