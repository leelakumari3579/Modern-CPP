#include <iostream>
#include <queue>
using namespace std;
class stack
{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x)
    {
        if(q1.empty())
            q1.push(x);
        else if (!q1.empty())
        {
            q2.push(x);
            while (!q1.empty())
            {
                q2.push(q1.front());
                q1.pop();
            }
            // swap(q1, q2);
            q1.swap(q2);
        }
    }
    void pop()
    {
        if (q1.empty())
        {
            cout << "no element to pop" << endl;
        }
        q1.pop();
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};

int main()
{
    stack s;
    s.push(1);
    s.push(4);
    s.push(5);
    s.push(0);
    s.push(2);
    cout << "top element is:" << s.top() << endl;
    s.pop();
    cout << "top element is:" << s.top() << endl;
    s.pop();
    cout << "top element is:" << s.top() << endl;
    s.pop();
    cout << "top element is:" << s.top() << endl;
    s.pop();
    cout << "top element is:" << s.top() << endl;
    s.pop();
}
