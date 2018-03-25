//Program to implement a Queue using two Singly Linked List

#include<iostream>
#include<cstdlib>
#include"SLL.cpp"

using namespace std;

class queue 
	/*   			

	objective: Create a class to implement Queue using STL Stack
	input parameters: none
	output value: none
	description:  Class definition
	approach: Class definition provides data member and member functions for the Queue class
	*/
{

	SLinkedList<int> sll;
	int curr_size;		// current size of the Q
	public:
	queue();
	void dequeue();
	void enqueue(int);
	int front();  				// returns front element
        bool isEmpty();
	void queue_status(); 
};

queue::queue(){
    /*
    Objective: To construct an object of class queue and initialize size of queue with 0.
    Input: None
    Output: None
    Return value: None
    */
    curr_size = 0;    
}

bool queue::isEmpty(){
    /*
    Objective: To test whether the queue is empty.
    Input: None
    Output: None
    Return value: true, if queue is empty
                  false, if queue is not empty.
    */
    if( sll.empty() )
        return true;
    else
        return false;
}

void queue::enqueue(int ele){
    /*
    Objective: To insert an element at the rear of queue.
    Input: ele -> The element to be inserted.
    Output: None
    Return value: None
    */
    sll.addBack(ele);
    curr_size++;
}

void queue::dequeue(){
    /*
    Objective: To remove the element from the front of queue.
    Input: None
    Output: None
    Return value: None
    */
    if( !isEmpty() ){
	curr_size--;
	sll.removeFront();
    }
}

int queue::front(){
    /*
    Objective: To find the front element of the queue.
    Input: None
    Output: None
    Return value: element at the front, if queue is not empty
                  NULL, if queue is empty
    */
    if( !isEmpty() )
        return sll.front();
}

void queue::queue_status(){
    /*
    Objective: To display the queue
    Input: None
    Output: Queue data
    Return value: None
    */
    cout<<"\n\n------------------------------Queue----------------------------------\n";
    sll.print();
    cout<<"\n--------------------------------------------------------------------";
}


int main(){
    /*
    Objective: To perform various queue operations.
    */
    queue q;
    int choice;
    while(1){
    cout<<"\n\n\t\t\tQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.PRINT QUEUE\n5.EXIT\n\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1:
                cout<<"\nEnter element: ";
		int ele;
		cin>>ele;
                q.enqueue(ele);
		q.queue_status();            
		break;
            
        case 2: if(!q.isEmpty()){
		q.dequeue();
                cout<<"\nElement removed!";
            }
            else
                cout<<"\nQueue empty!!Cannot perform deque!!";
            q.queue_status();
            break;
                
        case 3: if(!q.isEmpty())
                cout<<"\nFront element: "<<q.front();
            else
                cout<<"\nQueue is empty!!";
            break;
                
        case 4: q.queue_status();
            break;
                
        case 5: exit(0);
        
        default: cout<<"Invalid choice!!";
            break;
    }
    }
    return 0;
}





