#include<iostream>
using namespace std;
#include<stack>

stack<int> s;

void input(){
	
	/*
	Objective: This function takes a number as a input and pushes it in a stack.
	Input parameters: None
	Output: None 
	Side effects: Size of the stack is increased by 1 as a number is pushed to it.
	Return Value: None
	*/
	
	int x;
	cout<<"\nEnter number : ";
	cin>>x;
	s.push(x);
}

void reverse(){
	
	/*
	Objective: This function prints the number in the stack in reverse order.
	Input parameter: None
	Functions used: empty() -> returns True if stack is empty, otherwise False.
					top()   -> returns top element of the stack.
					pop()   -> removes the top element from the stack 
	Return value: None
	Side effects: The stack has been emptied.
	*/
	
	cout<<"\n\t\tNumber in reverse order";
	while(!s.empty()){
		cout<<"\n"<<s.top();
		s.pop();
	}
}

int main(){
	/*
	objective: To reverse given set of numbers using function input() and reverse()
	*/
	cout<<"\n\t\tPROGRAM TO REVERSE A NUMBER";
	int n;
	cout<<"\n\nHow many number do you want: ";
	cin>>n;
	while(n--!=0){
		input();
	}
	reverse();
	return 0;	
}
