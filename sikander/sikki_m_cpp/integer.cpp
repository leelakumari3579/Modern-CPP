#include<iostream>
#include<stack>
#include<string>
#include<queue>
#include<algorithm>
#include<typeinfo>
using namespace std;
//pclintplus.com
/*
template<class keyType,class valueType>
class map{
    keyType key;
    valueType value;
};
int main(){
    int a=5;
    decltype(a) b;
    cout<<typeid(a).name()<<endl;
    cout<<typeid(b).name()<<endl;
    string s[]={"Mallika","Ravi","Varma","Poojitha","Varsha"};
    sort(begin(s),end(s),[](const string &s1,const string &s2)->bool{
                        return s1.length()>s2.length();}
        );
    for(string ele:s)
        cout<<ele<<endl;

}
*/
class Integer{
    int value;
    public:
        Integer(int p_value=0):value(p_value){}
        Integer(const Integer &old){
            cout<<"\nCopy Constructor";
            value=old.value;
        }
        Integer & operator =(const Integer& old);
        Integer & operator =(const Integer& old){
            cout<<"\nOperator = ";
            value=old.value;
        }
        Integer & operator++(){   //without reference it will give value as only 6.
                                  //it will not call with the same object.
            cout<<"\nOperator ++ "<<this<<endl;
            ++value;
            return *this;
        }
        Integer operator +(Integer o){

        }
        friend ostream& operator<<(ostream& out, const Integer& obj);

};
ostream& operator <<(ostream& out, const Integer& obj){
    cout<<obj.value<<endl;
    return out;
}
int main(){
    /*
    Integer a=5;
    Integer b=10;
    stack<Integer> s;
    cout<<"\n----------------------------";
    s.push(a+b);
    cout<<"\n----------------------------";
    s.emplace(a+b);
    cout<<"\n----------------------------";
    */
    // Integer obj{5};
    // ++++obj;
    // cout<<obj;

    //FIFO 
    queue<int> q;
    q.push(10);
    q.pop();
    q.front();
    q.back();//returns the last element
}