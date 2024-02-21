#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Book
{
private:
    int bookid;
    char bookname[20];
    char authorname[20];
    int price;
    int NumberofdaysUsed;

public:
    Book()
    {
        this->bookid = 0;
        strcpy(bookname, "xx");
        strcpy(authorname, "yy");
        this->price = 0;
        this->NumberofdaysUsed = 0;
    }

    int getBookid() const
    {
        return bookid;
    }
    void setBookid(int bookid_)
    {
        this->bookid = bookid_;
    }

    char *getBookname()
    {
        return bookname;
    }

    void setBookname(char *bookname_)
    {
        strcpy(bookname, bookname_);
    }

    char getAuthorname()
    {
        return authorname[0];
    }

    void setAuthorname(char *authorname_)
    {
        strcpy(authorname, authorname_);
    }

    int getPrice() const
    {
        return price;
    }

    void setPrice(int price_)
    {
        this->price = price_;
    }

    int getnumberofdaysUsed() const
    {
        return NumberofdaysUsed;
    }

    void setNumberofdaysUsed(int numberofdaysUsed)
    {
        this->NumberofdaysUsed = numberofdaysUsed;
    }

    int calculatefine(int numberofdaysUsed);
    void accept(int b, int p, int d, const char bn[], const char an[]);
    void display();
};

#endif // HEADER_H