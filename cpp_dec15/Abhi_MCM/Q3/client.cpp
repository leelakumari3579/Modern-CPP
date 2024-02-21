#include <iostream>
#include <string>
#include <cstring>
#include "header.h"
using namespace std;

void add(Loan *ptr, int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << "Enter name : " << endl;
        char c[3];
        for (int i = 0; i < 3; i++)
            cin >> c[i];

        ptr[i].insertRecord(c);
    }
}

void search(Loan *ptr, long int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (ptr[i].getLoanNumber() == x)
        {
            cout << "The record for loan number " << x << " is found" << endl;
            ptr[i].PrintRecord();
        }
        else if (i >= n)
            cout << "There's no record for loan number " << x << endl;
    }
}

void countCustomers(Loan *ptr, int n)
{
    int maxi = ptr[0].calculateInterest(ptr[0].getAmount());
    int object = 0;
    for (int i = 0; i < n; i++)
    {
        if (ptr[i].calculateInterest(ptr[i].getAmount()) > maxi)
        {
            maxi = ptr[i].calculateInterest(ptr[i].getAmount());
            object = i;
        }
    }

    cout << "The person with highest interest amount is : ";
    ptr[object].PrintRecord();
}

int main()
{
    int n;
    cout << "Enter the number of loan objects : ";
    cin >> n;
    Loan *ptr = new Loan[n];

    cout << "<<<<ENTER TO BANK WORLD>>>>" << endl;
    int c;
    while (1)
    {
        cout << "Press 1 : To add a record in bank" << endl;
        cout << "Press 2 : To display all records" << endl;
        cout << "Press 3 : To search a record in bank" << endl;
        cout << "Press 4 : Find record with highest Loan" << endl;
        cout << "Press 0 : To exit the Bank world" << endl;
        cin >> c;

        switch (c)
        {
        case 0:
            exit(0);

        case 1:
            add(ptr, n);
            break;

        case 2:
            for (int i = 0; i < n; i++)
            {
                ptr[i].PrintRecord();
                cout << endl;
            }
            break;

        case 3:
            long int x;
            cout << "Enter the loan number you want to search : " << endl;
            cin >> x;
            search(ptr, x, n);
            break;

        case 4:
            countCustomers(ptr, n);
            break;

        default:
            cout << "Press valid Digit" << endl;
        }
    }
    delete []ptr;
}