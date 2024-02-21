#include<iostream>
#include<string>
using namespace std;

class A{
      public :  
    int a;
    int b;
    A(int p_a=0, int p_b=0 ){
        a=p_a;
        b=p_b;
    }
    A operator - (A  &obj);
    // A operator ++ ( int){
    //     A temp;
    //     temp.a=a++;
    //     return temp;
    // }
    int func(){
      return a;  
    }
};
A A:: operator - (A &obj){
    A temp;
    temp.a=a - obj.a;
    temp.b=b - obj.b;
    return temp;
}

int main(){
    A obj1(12,13);
    A obj2(11,10);
    A obj3=obj1-obj2;
    // obj1 ++;
    cout << obj3.func() << endl;

}