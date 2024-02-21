#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
void print(stack<int> s){

}
int main(){
    string str="{{()()[]{}}}";
    stack<char> s;
    int flag=1;
    for(int i=0;i<str.length();i++){
        if(str[i]== '{' || str[i]== '[' || str[i]== '('  ){ s.push(str[i]);}
        else {
            if(str[i] == '}' && !s.empty() && s.top()=='{' ){  s.pop();}
            else {
                if(str[i] == ')' &&  !s.empty() && s.top()=='('){  s.pop();}
                else{
                    if((str[i] == ']' && !s.empty() && s.top()=='[')){    s.pop();}
                    else{
                        s.push(str[i]);
                        break;
                    }
                }
            }
        }
    }
    if(s.empty()){
         cout << "String is balanced \n";
    }
    else{
        cout << "String is  not balanced \n";
    }
    
    return 0;
}