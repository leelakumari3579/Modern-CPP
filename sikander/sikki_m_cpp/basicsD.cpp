#include<iostream>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
using namespace std;
class MyStack
{
    queue<int> q;
    public:
        MyStack(){}
        void push(int x)
        {
            q.push(x);
        }
        int pop()
        {
            queue<int> temp;
            while(q.size()!=1)
            {
                temp.push(q.front());
                q.pop();
            }
            int deletedElement=q.front(); 
            q.pop();
            while(temp.empty()==false)
            {
                q.push(temp.front());
                temp.pop();
            }
            return deletedElement;
        }
        // int top()
        // {
        //     queue<int> temp;
        //     while(q.size()!=1)
        //     {
        //         temp.push(q.front());
        //         q.pop();
        //     }
        //     int topElement;
        // }
        //bool isEmpty(){}
};
int main(){
    queue<int> q;
    stack<int> s1;
    stack<int> s2;
    s1.push(10);
    s1.push(20);
    s1.push(30);
    s1.pop();
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    while(!s2.empty()){
        cout<<s2.top()<<"   ";
        s2.pop();
    }

    MyStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.pop();
    return 0;
}