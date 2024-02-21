#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
void print(stack<int> s){

}
int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout<< "size : " << s.size() << endl;
    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();}
    
    return 0;
}