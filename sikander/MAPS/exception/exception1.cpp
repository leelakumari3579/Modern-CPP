#include<iostream>
#include<string>
using namespace std;

void func(int  a){
    try{
        if(a%2==0) throw runtime_error("even number");
        else {
            throw "odd number";
        }
        throw;

    }
    catch(string b){
        cout<<b<<endl;
    }
    catch(const exception &e){
        cout << " a is : " << e.what() << endl;

    }
    catch(...){
        cout << "default catch block"<< endl;
    }
}
int main(){
    int a=1;
    func(a);
}