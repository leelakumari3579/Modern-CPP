#include <iostream>
#include <cstring>
#include "header.h"
using namespace std;
void showAuthor(Book bk[])
{
    for (int i = 0; i < 3; i++)
    {
        if (bk[i].getAuthorname() == 'A')
            cout << "The book names whose author's name start with A are : " << bk[i].getBookname() << endl;
        
        else if (i == 3)
            cout << "No book has author name starting with 'A" << endl;
    }
}

void showPrice(Book bk[])
{
    for (int i = 0; i < 3; i++)
    {
        if (bk[i].getPrice() >= 2500)
            cout << "The book names whose price less than Rs-2500 are : " << bk[i].getBookname() << endl;
        
        else if (i == 3)
            cout << "No book has price less than Rs-2500" << endl;
    }
    
}
int main()
{
    Book bk[3];
    bk[0].accept(1, 100, 5, "animal", "Abhi");
    bk[1].accept(2, 200, 20, "Hustle", "ankita");
    bk[2].accept(3, 2500, 45, "Harry Potter", "aman");

    cout << "The books details are as follows : " << endl;
    for (int i = 0; i < 3; i++)
    {
        bk[i].display();
    }

    cout << "The fine associated with each books are : " << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "Book id : " << i + 1 << " ,"
             << "Fine : " << bk[i].calculatefine(bk[i].getnumberofdaysUsed())<<endl;
    }

    showAuthor(bk);
    showPrice(bk);

    return 0;
}