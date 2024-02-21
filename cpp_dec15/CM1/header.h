#ifndef HEADER_H
#define HEADER_H

#include<cstring>
#include<iostream>
class Inventory
{
private:
    std::string description_of_product;
    int balancestrock;
    int productcode;
public:
 Inventory(std::string,int,int);
     Inventory();

     int getBalancestrock() const { return balancestrock; }
     void setBalancestrock(int balancestrock_) { balancestrock = balancestrock_; }

     int getProductcode() const { return productcode; }
     void setProductcode(int productcode_) { productcode = productcode_; }

     std::string descriptionOfProduct() const { return description_of_product; }
     void setDescriptionOfProduct(const std::string &descriptionOfProduct) { (description_of_product = descriptionOfProduct); }

    void purchase();
    void sale(int);
    void search(int);
};


#endif // HEADER_H


// char *getBookname() { return bookname; }
// void setBookname(char *bookname_) { strcpy(bookname,bookname_); }


// char *getBookname()
//     {
//         return bookname;
//     }

// void setBookname(char *bookname_)
//     {
//         strcpy(bookname, bookname_);
//     }
