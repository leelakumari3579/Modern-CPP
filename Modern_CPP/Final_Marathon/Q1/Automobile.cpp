#include "Automobile.h"

std::ostream &operator<<(std::ostream &os, const Automobile &rhs) {
    os << "_id: " << rhs._id
       << " _brand: " << rhs._brand
       << " _category: "; 
       switch(rhs._category)
       {
            case Category::DEFENSE:
                os<<"DEFENECE";
                break;
            case Category::PRIVATE:
                os<<"PRIVATE";
                break;
            case Category::TRANSPORT:
                os<<"TRANSPORT";
                break;        
       };
      os << " _price: " << rhs._price
       << " _model: " << rhs._model;
    return os;
}

Automobile::Automobile(std::string id, std::string brand, Category category, float price, std::string model)
    :_id(id),_brand(brand),_category(category),_price(price),_model(model)
{
}

PrivilegeCategory Automobile::FindPrivilegeType()
{
    if(_category == Category::PRIVATE && _price >= 2500000)
    {
        return PrivilegeCategory::VIP;
    }
    else if(_category == Category::DEFENSE)
    {
        return PrivilegeCategory::GOVT;
    }
    else
    {
        return PrivilegeCategory::PERSONAL;
    }
}

float Automobile::GreenPassCost()
{
    if(_category == Category::PRIVATE or _category == Category::TRANSPORT)
    {
        return 0.1 * _price;
    }
    else
    {
        return 0.0f;
    }
}
