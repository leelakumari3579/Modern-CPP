#include<iostream>
#include<cctype>
#include<string>
void remove_spcl_chars(std::string s)
{
    std::string s1="";
    for(int i=0;i<s.size();i++)
    {
        //if(isalpha(s[i])) 
        if(s[i]>'A' && s[i]<'Z'||s[i]>'a' && s[i]<'z')
        {
            s1 +=s[i];
        }
    }
    std::cout<<s1;
}
int main()
{
    std::string s="g.leel@ kumar!";
    remove_spcl_chars(s);
    return 0;
}