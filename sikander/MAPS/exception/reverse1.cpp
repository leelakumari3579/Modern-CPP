#include <iostream>
#include <string>
#include <stack>
using namespace std;
int main()
{
    string str = "  hello  wolrd  ";
    stack<char> s;
    int flag = 0;
    for (int i = str.length() - 1; i >= 0; i--)
    {
        if (str[i] == ' ')
        {
            while (s.empty() == false)
            {
                cout << s.top();
                s.pop();
            }
            if (i == 0)
            {
            }
        }
        else{
            s.push_back(str[i]);
        }
        if()
    }

    return 0;
}