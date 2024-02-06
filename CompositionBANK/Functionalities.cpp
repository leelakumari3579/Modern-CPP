#include "Functionalities.h"

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

void Print(Container &data)
{
    for(auto ele:data) //for(std::shared_ptr<BankAccount> acc: data)
    {
        std::cout<<"account name "<<ele->accountHolderName()<<std::endl;
        std::cout<<"account number "<<ele->_accounaccountNumber()<<std::endl;
        //std::cout<<"account type "<<ele->accountType()<<std::endl;
    }
}
