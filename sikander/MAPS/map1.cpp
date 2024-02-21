#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
class Integer{
    public:
    int value;
    Integer(){}
    Integer(int p_value=0){
        value=p_value;
    }
    Integer operator ++ (){
            ++value;
            return *this;
    }
    friend ostream & operator << (ostream& out , const Integer & obj);
};
ostream & operator << (ostream &out , const Integer & obj){

    return out;
    
    }
int main(){
    Integer obj{5};
    ++++obj;
    cout << "value = " << obj.value << endl;
    int a=10;
    ++++a;
    cout << "a= " << a << endl;
    return 0;
}