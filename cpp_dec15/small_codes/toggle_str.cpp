#include<iostream>
//#include<cctype>
//#include<cstring>
int main()
{
    std::string s= "G Leela Kumari";
    for(int i=0;s[i]!='\0';i++)
    {
        if(isupper(s[i]))
            s[i]=tolower(s[i]);
        else if(islower(s[i]))
            s[i]=toupper(s[i]);
    }
    std::cout<<"toggled string "<<s;
    return 0;
}