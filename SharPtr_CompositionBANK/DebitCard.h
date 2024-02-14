#ifndef DEBITCARD_H
#define DEBITCARD_H
#include <string>
#include <iostream>
#include "DebitCardType.h"

class DebitCard
{
    private:
        const unsigned short _cvv;
        const long _cardNumber;
        const std::string&& _expiryDate;
        DebitCardType _cardType;
    public:
        DebitCard() = delete;
        DebitCard(const DebitCard&) = delete;
        DebitCard& operator=(const DebitCard&) = delete;
        DebitCard(DebitCard&&) = delete;
        DebitCard& operator=(DebitCard&&) = delete;
        // ~DebitCard() {std::cout<<"debit card destoyed with number "<<_cardNumber<<"\n";}
        ~DebitCard() = default;
        DebitCard(unsigned short cvv, long cardNumber, std::string&& expiryDate,  DebitCardType cardType);

        unsigned short cvv() const { return _cvv; }

        long cardNumber() const { return _cardNumber; }

        const std::string& expiryDate() const { return _expiryDate; }

        DebitCardType cardType() const { return _cardType; }
        
};

#endif // DEBITCARD_H
