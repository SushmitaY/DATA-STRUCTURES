#include<iostream>
#include<stack>
#include<string>
#include<regex>
using namespace std;

stack<char> s;

bool isOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;
}

int precedence(char op1, char op2){
	/*
	returns 1 id op1>op2
	else 0
	*/
	string operate = "-+*/^"; 
	if(op1==op2)
		return 0;
	if(operate.find(op1)>operate.find(op2))
		return 1;
	else 
		return -1;
} 


void toPostFix(string exp){
	
	for(int i=0;i<exp.length();i++){
		
		if( exp.at(i) == '('){
			s.push('(');
		}
		else if( exp.at(i) == ')'){
			while( !s.empty() && s.top()!='('){
				cout<<s.top()<<" ";
				s.pop();
			}
			s.pop();
		}
		else if(!isOperator(exp.at(i))){
			cout<<exp.at(i)<<" ";
		}
		else{
			
			char opr = exp.at(i);
			if( s.empty() )
				s.push(opr);
			else if(  precedence(opr , s.top() )>0)
				s.push(opr);
			else{
				while( !s.empty() && s.top()!='(' && precedence(opr,s.top())<=0 ){
					cout<<s.top()<<" ";
					s.pop();
				}
				s.push(opr);
			}
		}
	}
	while(!s.empty()){
		cout<<s.top();
		s.pop();
	}
}

int main(){

	string exp;
	cout<<"\nEnter an expression: ";
	getline(cin,exp);
	toPostFix(exp);
	cout<<endl;
	return 0;
}

