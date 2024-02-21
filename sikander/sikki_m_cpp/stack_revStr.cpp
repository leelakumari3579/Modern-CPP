#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<list>
#include<stack> 
int main()
{
    std::stack<char> s;
    char x;
    std::string st="Today is Thursday ";
    for(int i=0;i<st.length();i++)
    {
        if(s.empty())
            s.push(st[i]);
        else if(st[i]!=' ' && !s.empty())
            s.push(st[i]);
        else
        {
            while(!s.empty())
            {
                x=s.top();
                s.pop();
                std::cout<<x;
            }
            std::cout<<" ";
        }
    }
}