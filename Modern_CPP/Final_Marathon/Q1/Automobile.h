#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>
#include <ostream>
#include "Category.h"
#include "PrivilegeCategory.h"

class Automobile
{
private:
    std::string _id{"0x"};
    std::string _brand{"xyz"};
    Category _category{Category::PRIVATE};
    float _price{0.0f};
    std::string _model{"abc"};

public:
    Automobile() = default;
    Automobile(const Automobile &) = delete;
    Automobile &operator=(const Automobile &) = delete;
    Automobile &operator=(Automobile &&) = delete;
    Automobile(Automobile &&) = delete;
    ~Automobile() = default;

    // perametarised constructor
    Automobile(std::string id, std::string brand, Category category, float price, std::string model);

    // member functions
    PrivilegeCategory FindPrivilegeType();
    float GreenPassCost();

    //getter setters
    std::string id() const { return _id; }
    void setId(const std::string &id) { _id = id; }

    std::string brand() const { return _brand; }
    void setBrand(const std::string &brand) { _brand = brand; }

    Category category() const { return _category; }
    void setCategory(const Category &category) { _category = category; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    std::string model() const { return _model; }
    void setModel(const std::string &model) { _model = model; }

    friend std::ostream &operator<<(std::ostream &os, const Automobile &rhs);
};

#endif // AUTOMOBILE_H
