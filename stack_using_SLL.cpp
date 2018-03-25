//Program to implement a Stack using two Singly Linked List

#include<iostream>
#include<cstdlib>
#include"SLL.cpp"

using namespace std;

class stack{

	SLinkedList<int> sll;
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
	curr_size = 0;
}

void stack::push(int ele){
    /*
    Objective: To push an element onto the stack.
    Input: ele -> The element to be pushed
    Output: None
    Return value: None
    */
  
   sll.addFront(ele);
   curr_size++;
}

bool stack::isEmpty(){
    if(sll.empty())
	return true;	
    else
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
	    sll.removeFront();
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
	return sll.front();
}

void stack::stack_status(){
    /*
    Objective: To print the stack
    Input: None
    Output: Stack data
    Return value: None
    */
    cout<<"\n\n-------------------------Stack---------------------------\n";
    sll.print();
    cout<<"\n----------------------------------------------------------";
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

