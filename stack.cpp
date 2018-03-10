//PROGRAM TO PERFORM VARIOUS STACK OPERATIONS

#include<iostream>
#include<cstdlib>
#define MAX_SIZE 100

using namespace std;

template<typename T>

class stack{

    /*
    Class definition for "stack" data structure which follows Last in First out(LIFO) protocol
    */
    T *arr;
    int top;
    int capacity;

    public:
        stack(int c=MAX_SIZE);
        ~stack();
        T input();
        void push(T);
        T pop();
        T peek();
        int size();
        bool isEmpty();
        bool isFull();
        void stack_status();
};

template<typename T>
stack<T>::stack(int c){
    /*
    Objective: To construct an object of class stack and initialize capacity, top and arr.
    Input: Capacity of stack
    Output: None
    Return value: None
    */
    capacity = c;
    top = -1;
    arr = new T[capacity];
}

template<typename T>
stack<T>::~stack(){
    /*
    Objective: To destruct the object of class stack.
    Input: None
    Output: None
    Return value: None
    */
    delete []arr;
}

template<typename T>
T stack<T>::input(){
    /*
    Objective: To take a input from console.
    Input: None
    Output: None
    Return value: The input taken.
    */
    T ele;
    cin>>ele;
    return ele;
}

template<typename T>

int stack<T>::size(){
    /*
    Objective: To calculate size of the stack.
    Input: None
    Output: None
    Return value: Size of the stack.
    */
    return top+1;
}

template<typename T>

bool stack<T>::isEmpty(){
    /*
    Objective: To test whether the stack is empty.
    Input: None
    Output: None
    Return value: true, if stack is empty
                  false, if stack is not empty
    */
    if( size() == 0 )
        return true;
    else
        return false;
}

template<typename T>

bool stack<T>::isFull(){
    /*
    Objective: To test whether the stack is full.
    Input: None
    Output: None
    Return value: true, if stack is full
                  false, if stack is not full
    */
    if( size() == capacity )
        return true;
    else
        return false;
}

template<typename T>

void stack<T>::push(T ele){
    /*
    Objective: To push an element of type T onto the stack.
    Input: ele -> The element to be pushed
    Output: None
    Return value: None
    */
    if( !isFull() )
        arr[++top] = ele;
}

template<typename T>

T stack<T>::pop(){
    /*
    Objective: To pop the top element out of the stack.
    Input: None
    Output: None
    Return value: top element, if stack is not empty
                  NULL, if stack is empty
    */
    if( !isEmpty() )
        return arr[top--];
}

template<typename T>

T stack<T>::peek(){
    /*
    Objective: To find the top element of the stack.
    Input: None
    Output: None
    Return value: top element, if stack is not empty
                  NULL, if stack is empty
    */
    if( !isEmpty() )
        return arr[top];
}

template<typename T>

void stack<T>::stack_status(){
    /*
    Objective: To print the stack
    Input: None
    Output: Stack data
    Return value: None
    */
    cout<<"\n\n------Stack------\n";
    int i=top;
    while(i>=0){
        cout<<"\t"<<arr[i--]<<endl;
    }
    cout<<"-----------------";
}

int main(){
    /*
    Objective: To perform various stack operations.
    */
    int c;
    cout<<"\nEnter capacity of stack: ";
    cin>>c;
    stack<int> s(c);
    int choice;
    while(1){
    cout<<"\n\n\t\t\tSTACK OPERATIONS\n\n1.PUSH\n2.POP\n3.TOP\n4.SIZE\n5.PRINT STACK\n6.EXIT\n\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1: if(!s.isFull()){
                cout<<"\nEnter element: ";
                s.push(s.input());
                s.stack_status();
            }
            else
                cout<<"\nStack Full!!Cannot push!!";
            break;
            
        case 2: if(!s.isEmpty()){
                cout<<"\nElement popped: "<<s.pop();
                s.stack_status();
            }
            else
                cout<<"\nStack empty!!Cannot pop!!";
            break;
                
        case 3: if(!s.isEmpty())
                cout<<"\nTop element: "<<s.peek();
            else
                cout<<"\nStack is empty!!";
            break;
                
        case 4: cout<<"\nSize of stack: "<<s.size();
            break;
                
        case 5: s.stack_status();
            break;
                
        case 6: exit(0);
        
        default: cout<<"Invalid choice!!";
            break;
    }
    }
    return 0;
}
