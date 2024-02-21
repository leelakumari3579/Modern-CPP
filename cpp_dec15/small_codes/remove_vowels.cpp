#include<iostream>
int main()
{
    /*
    std::string s="leela kumari";
    std::cout<<"string without vowels: ";
    for(int i=0;i<s[i]!=0;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            continue;
        else
        {
            std::cout<<s[i];
        }
    }
    */
    int j=0;
    std::string s="leela kumari";
    for(int i=0;i<s[i]!=0;i++)
    {
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            s[j++]=s[i];
    }
    while (j<s.size())
    {
        s[j]='\0';
        j++;
    }
    std::cout<<"string with only vowels: "<<s;    
    return 0;
}