#include<iostream>
#include<string>
#include<stack>
#include<queue>

using namespace std;

bool isPalindrome(string str){

	/*
	Objective: To test whether a string is palindrome or not.
	Input:  A string
	Return value: True if the string is palindrome, False otherwise
	
	Approach: Using standard stack and queue.
	*/

	stack<char> s;
	queue<char> q;
	for(int i=0;i<str.length();i++){
		s.push(str[i]);
		q.push(str[i]);
	}
	while(!s.empty()){
		if(s.top() != q.front() )	
			return false;
		s.pop();
		q.pop();
	}
	return true;
}

int main(){

	string str;
	cout<<"\nEnter string: ";
	cin>>str;
	if(isPalindrome(str))
		cout<<"YES\n";
	else
		cout<<"NO\n";
	return 0;
}
