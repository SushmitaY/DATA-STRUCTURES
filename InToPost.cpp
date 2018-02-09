//Program to convert simple mathematical infix expression to postfix expression

#include<iostream>
#include<stack>
#include<string>

using namespace std;

stack<char> s;

bool isOperator(char ch){
	/*
	Objective: To check whether a character is a mathematic operator.
	Input: ch -> A Character to be tested
	Output: None
	Return value: True, if ch is an operator.
		False, if ch is not an operator.
	*/
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
		return true;
	else
		return false;
}

int precedence(char opr){
	
	/*
	Objective: To calculate precedence of an operator.
	Input: opr -> A character containing operator.
	Output: None
	Return value: An integer that denotes the precedence value of the operator.
		 Higher the operator's precedence, greater will be the integer value.
	Description: Operator		Precedence value
		       +,-			1
		       *,/			2
		       ^			3
	*/ 
	if(opr == '+' || opr == '-')
		return 1;
	if(opr == '*' || opr == '/')
		return 2;
	if(opr == '^')
		return 3;
} 


void toPostFix(string exp){
	
	/*
	Objective: To convert an infix expression to postfix expression.
	Input: exp -> An infix expression
	Output: A postfix expression equivalent to the input.
	Return value: None
	Approach: using stack and functions isOperator(...) and precedence(...) 
	*/
	
	for(int i=0;i<exp.length();i++){
		//opr contains the currently scanned character in the expression
		char opr = exp.at(i);
		if( opr == '('){
			//scanned character is an opening bracket '(' 
			s.push('(');
		}
		else if( opr == ')'){
			//scanned character is an closing bracket ')'
			while( !s.empty() && s.top()!='('){
				cout<<s.top()<<" ";
				s.pop();
			}
			//pop ')' from stack
			s.pop();	
		}
		else if(!isOperator(opr)){
			//scanned character is an operand
			cout<<opr<<" ";
		}
		else{
			//scanned character is an operator
			if( s.empty() )
				s.push(opr);	
			else if(  precedence(opr) > precedence(s.top()) )
				s.push(opr);
			else{
				while( !s.empty() && s.top()!='(' && precedence(opr) <= precedence(s.top()) ){
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
	
	/*
	Objective: Take an infix expression input from console and output the postfix expression to the console.
	Input parameters: None
	Output: Postfix expression
	Approach: using function toPostFix()
	*/
	
	string exp;
	cout<<"\nEnter an infix expression: ";
	getline(cin,exp);
	toPostFix(exp);
	cout<<endl;
	return 0;
}

