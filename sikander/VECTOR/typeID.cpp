// C++ program to show the use of typeid operator 

#include <iostream> 
#include <typeinfo>
#include<string> 
using namespace std; 

int main() 
{ 
	int i = 5; 
	float j = 1.0; 
	char c = 'a'; 

	// Get the type info using typeid operator 
	const type_info& ti1 = typeid(i * j); 
	const type_info& ti2 = typeid(i * c); 
	const type_info& ti3 = typeid(c); 

	// Print the types 
	cout << "ti1 is of type "
		<< ti1.name() << endl; 

	cout << "ti2 is of type "
		<< ti2.name() << endl; 

	cout << "ti3 is of type "
		<< ti3.name() << endl; 
    string name="uma";
        cout << "string of type of name  "
		<< typeid(name).name() << endl; 
        cout << "string of type "
		<< typeid("mahi").name() << endl; 
    cout<< sizeof(name)<< endl;
    int arr[3];
    cout<< sizeof(arr)<< endl;
    cout<< sizeof(arr[1])<< endl;
    string arrs[3];
    cout<< sizeof(arrs)<< endl;
    cout<< sizeof(arrs[1])<< endl;

	return 0; 
} 
