//Program to implement a Stack using two Queues

#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

class stack{
	/*   			
	objective: Create a class to implement Stack using STL Queues
	input parameters: none
	output value: none
	description:  Class definition
	approach: Class definition provides data member and member functions for the Stack class
	*/
	queue<int> q1,q2;
	int curr_size;
	public:
	   stack();
	   void push(int);
	   void pop();
           int top();
	   bool isEmpty();
	   void stack_status();
};

stack::stack(){
    /*
    Objective: To construct an object of class stack and initialize size of the stack with 0.
    Input: None
    Output: None
    Return value: None
    */
	curr_size = 0;
}

void stack::push(int ele){
    /*
    Objective: To push an element onto the stack.
    Input: ele -> The element to be pushed
    Output: None
    Return value: None
    */
   curr_size++;
   q2.push(ele);
   while(!q1.empty()){
		q2.push(q1.front());
		q1.pop();
   }
   queue<int> temp = q1;
   q1 = q2;
   q2 = temp;
}

bool stack::isEmpty(){
    if(q1.empty())
	return true;	
    return false;
}

void stack::pop(){
    /*
    Objective: To pop the top element out of the stack.
    Input: None
    Output: None
    Return value: top element, if stack is not empty
                  NULL, if stack is empty
    */
    if(!isEmpty()){
	    curr_size--;
	    q1.pop();
    }
}

int stack::top(){
    /*
    Objective: To find the top element of the stack.
    Input: None
    Output: None
    Return value: top element, if stack is not empty
                  NULL, if stack is empty
    */
    if( !isEmpty() )
	return q1.front();
}

void stack::stack_status(){
    /*
    Objective: To print the stack
    Input: None
    Output: Stack data
    Return value: None
    */
    cout<<"\n\n------Stack------\n";
    if(!isEmpty()){
	queue<int> temp = q1;
	while(!temp.empty()){
		cout<<"\t"<<temp.front()<<"\n";
		temp.pop();		
	}
    }
    cout<<"-----------------";
}

int main(){
    /*
    Objective: To perform various stack operations.
    */
    stack s;
    int choice;
    while(1){
    cout<<"\n\n\t\t\tSTACK OPERATIONS\n\n1.PUSH\n2.POP\n3.TOP\n4.PRINT STACK\n5.EXIT\n\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1: cout<<"\nEnter element: ";
		int ele;
		cin>>ele;
                s.push(ele);
                s.stack_status();
            break;
            
        case 2: if(!s.isEmpty()){
			s.pop();
                	cout<<"\nElement popped!!";
                }
            else
                cout<<"\nStack empty!!Cannot pop!!";
	    s.stack_status();
            break;
                
        case 3: if(!s.isEmpty())
                cout<<"\nTop element: "<<s.top();
            else
                cout<<"\nStack is empty!!";
            break;
                
        case 4: s.stack_status();
            break;
                
        case 5: exit(0);
        
        default: cout<<"Invalid choice!!";
            break;
    }
    }
return 0;
}
