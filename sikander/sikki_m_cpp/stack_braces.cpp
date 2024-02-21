#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<list>
#include<stack> //top,empty,pop,push,size
// CPP program to check for balanced brackets. 
// #include <bits/stdc++.h> 
using namespace std; 

// function to check if brackets are balanced 
bool areBracketsBalanced(string expr) 
{ 
	stack<char> s; 
	char x; 

	// Traversing the Expression 
	for (int i = 0; i < expr.length(); i++) 
	{ 
		if (expr[i] == '(' || expr[i] == '['
			|| expr[i] == '{') 
		{ 
			// Push the element in the stack 
			s.push(expr[i]); 
			continue; 
		} 

		// IF current current character is not opening bracket, then it must be closing. So stack cannot be empty at this point

		if (s.empty()) 
			return false; 
		// cout<<expr[i]<<" ";
		switch (expr[i]) { 
		case ')': 
			
			// Store the top element in a 
			x = s.top(); 
			s.pop(); 
			// cout<<x<<" ";
			if (x == '{' || x == '[') 
				return false; 
			break; 

		case '}': 

			// Store the top element in b 
			x = s.top(); 
			s.pop(); 
			// cout<<x<<" ";
			if (x == '(' || x == '[') 
				return false; 
			break; 

		case ']': 

			// Store the top element in c 
			x = s.top(); 
			s.pop(); 
			// cout<<x<<" ";
			if (x == '(' || x == '{') 
				return false; 
			break; 
		} 
	} 

	// Check Empty Stack 
	return (s.empty()); 
} 

// Driver code 
int main() 
{ 
	string expr = "{()}[]"; 

	// Function call 
	if (areBracketsBalanced(expr)) 
		cout << "Balanced"; 
	else
		cout << "Not Balanced"; 
	return 0; 
} 


//  int main()
//  {
//     std::stack<std::string> s;
//     s.push("leela");
//     s.push("nani");
//     s.push("gowri");
//     while(s.empty()==false)
//     {
//         std::cout<<s.top()<<std::endl;
//         s.pop();
//     }
//     std::cout<<s.size()<<std::endl;

//  }
