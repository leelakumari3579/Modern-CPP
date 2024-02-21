#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
template <class keyType , class valueType>

class map{
    keyType key;
    valueType value;

};

int main(){
    string s[]={"uma" , "mahi" , "gow" , "manu"};
    sort(begin(s),end(s),greater<string>());
   // sort(begin(s),end(s),[](const string s1,const string s2){ return s1.length() < s2.length();});
    for(string ele: s){
        cout << ele << endl;
    }
    return 0;

}