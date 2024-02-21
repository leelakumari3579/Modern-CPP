#ifndef HEADER_H
#define HEADER_H
#include<cstring>
class Book
{
    private:
        int Bookid;
        char bookname[30];
        char authorname[30];
        int price;
        int NumberofdaysUsed;
    public:
        Book();
        // Book(int,char[],char[],int,int);

        int bookid() { return Bookid; }
        void setBookid(int bookid) { Bookid = bookid; }

        char *getBookname() { return bookname; }
        void setBookname(char *bookname_) { strcpy(bookname,bookname_); }

        char *getAuthorname() { return authorname; }
        void setAuthorname(char *authorname_) { strcpy(authorname,authorname_); }

        int getPrice() { return price; }
        void setPrice(int price_) { price = price_; }

        int numberofdaysUsed() { return NumberofdaysUsed; }
        void setNumberofdaysUsed(int numberofdaysUsed) { NumberofdaysUsed = numberofdaysUsed; }

        void calculateFine();
        void accept();
        void display();
        void showAuthor();
        void showPrice();        

};

#endif // HEADER_H
