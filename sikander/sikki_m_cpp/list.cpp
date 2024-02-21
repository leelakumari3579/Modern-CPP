#include<vector> 
#include<iostream>
#include<string>
#include<algorithm>
#include<list>
using namespace std;

/*
iterator vector : pointer+int, pointer-int, pointer-pointer, pointer++, pointer--, <, >, <=, >=, ==, !=
iterator list : pointer++, pointer--, ==, !=
*/
template<class T>

void display(T& names)
{
    for(auto ele:names)
        cout<<ele<<"--->";
    cout<<endl;
}
int main()
{
    vector<string> namesV={"leela","nani","venkat","satya","sai","gowri"};
    list<string> names={"sravya","leela","nani","siri","yamini","sai","mounika"};
    // names.push_back("leela");
    // names.push_back("nani");
    // names.push_back("venkat");
    // names.push_back("stya");
    // names.push_back("sai");
    // names.push_back("gowri");

    auto it_v = begin(namesV);
    auto it_l = begin(names);

    // names.push_back("poori");
    // namesV.push_back("charry");

    // it_v = it_v+2;
    // ++++it_v;//venkat
    // cout<<*it_v;

    // while(it_v<end(namesV))
    // {
    //     cout<<*it_v;
    //     it_v++;
    // }  //->it will work with vectors but not work(<) with list
    // while(it_l!=end(names))
    // {
    //     cout<<*it_l<<"\t";
    //     it_l++;
    // } //== , != works in list

    // it_l;//sravya
    // it_l++; //leela
    //(++it_l)++; //nani
    //++(it_l++); //leela
    //++++(it_l++);//leela
    //++++(it_l);//nani
    // it_l++++; //leela -->post increments will increases but it only gives 2nd element
    //cout<<*it_l;

    // display(namesV);
    // display(names);
   
    // names.pop_back(); //gowri
    // display(names);

    // names.pop_front(); //leela
    // display(names);

    // list<string>::iterator it = max_element(begin(names),end(names));
    // cout<<"max name: "<<*it<<endl;

    // names.sort(); //sort(begin(names),end(nmaes)) will not work in list
    // display(names);
}