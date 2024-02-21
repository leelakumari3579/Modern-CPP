#include "header.h"
#include <iostream>
#include <cstring>
void Book::accept(int b, int p, int d, const char *bn, const char *an)
{
    bookid = b;
    price = p;
    NumberofdaysUsed = d;
    strcpy(bookname, bn);
    strcpy(authorname, an);
}

void Book ::display()
{
    cout << "Book id : " << this->bookid << endl;
    cout << "Name of the book : " << bookname << endl;
    cout << "Author of the book : " << authorname << endl;
    cout << "Price of the book : " << price << endl;
    cout << "No.of days the book was issued : " << NumberofdaysUsed << endl;
}

int Book::calculatefine(int n)
{
    int fine;
    if (n > 10 && n < 20)
        fine = 100;
    else if (n >= 20 && n < 30)
        fine = 200;
    else if (n >= 30 && n < 40)
        fine = 300;
    else if (n >= 40)
        fine = 500;
    else
        fine = 0;
    return fine;
}

//friend ostream & operator <<(ostream &out, Student &s);

/* ostream & operator <<(ostream &out, Student &s){
    out<<s.getR()<<endl;
    out<<s.getS()<<endl;
    return out;
}  */