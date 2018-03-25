#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> s;

void reverse(string str){
	
	/*
	Objective: This function prints reverse of the string.
	Input parameter: None
	Functions used: empty() -> returns True if stack is empty, otherwise False.
					top()   -> returns top element of the stack.
					pop()   -> removes the top element from the stack 
	Return value: None
	Side effects: The stack has been emptied.
	*/
	for(int i=0;i<str.length();i++)
		s.push(str[i]);
	cout<<"\nReversed string: ";
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
	cout<<"\n";
}

int main(){
	/*
	objective: To reverse given set of numbers using function input() and reverse()
	*/
	cout<<"\n\t\tPROGRAM TO REVERSE A STRING";
	string str;
	cout<<"\n\nEnter string: ";
	cin>>str;
	reverse(str);
        return 0;
}
