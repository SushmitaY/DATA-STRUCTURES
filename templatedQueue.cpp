#include <iostream>
#include <cstdlib>

#define SIZE 10

using namespace std;

template<typename T>
class queue 
	/*   			
	objective: Create a class to implement Queue(circular) using dynamically created array 
	input parameters: none
	output value: none
	description:  Class definition
	approach: Class definition provides data member and member functions for the Queue class
	*/
{

	T *arr;			// array to store queue elements
	int capacity;			// maximum capacity of the Q
	int front;			// front points to front element in the Q
	int rear;			// rear points to last element in the Q
	int count;			// current size of the Q
	public:

	queue(int size = SIZE);			// constructor
	~queue();	
	T input();
	void dequeue();
	void enqueue(T);
	T peek();  				// returns front element
	int size();				// returns current size of Q
	bool isEmpty();
	bool isFull();
	void queue_status(); 
};

template<typename T>
queue<T>::queue(int size){
    /*
    Objective: To construct an object of class queue and initialize capacity, front, rear and arr.
    Input: Capacity of queue
    Output: None
    Return value: None
    */
    capacity = size;
    front = -1;
    rear = -1;
    count = 0;
    arr = new T[capacity];
}

template<typename T>
queue<T>::~queue(){
    /*
    Objective: To destruct the object of class queue.
    Input: None
    Output: None
    Return value: None
    */
    delete []arr;
}

template<typename T>
T queue<T>::input(){
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
int queue<T>::size(){
    /*
    Objective: To calculate the number of elements currently in the queue.
    Input: None
    Output: None
    Return value: Size of the queue.
    */
    return count;
}

template<typename T>
bool queue<T>::isEmpty(){
    /*
    Objective: To test whether the queue is empty.
    Input: None
    Output: None
    Return value: true, if queue is empty
                  false, if queue is not empty.
    */
    if( size() == 0 )
        return true;
    else
        return false;
}

template<typename T>
bool queue<T>::isFull(){
    /*
    Objective: To test whether the queue is full.
    Input: None
    Output: None
    Return value: true, if queue is full
                  false, if queue is not full
    */
    if( size() == capacity )
        return true;
    else
        return false;
}

template<typename T>
void queue<T>::enqueue(T ele){
    /*
    Objective: To insert an element at the rear of queue.
    Input: ele -> The element to be inserted.
    Output: None
    Return value: None
    */
    if( !isFull() ){
	if( isEmpty() ){
		front = (front+1)%capacity;
	}
	rear = (rear+1)%capacity;
	arr[rear] = ele;
	count++;
   }
}

template<typename T>
void queue<T>::dequeue(){
    /*
    Objective: To remove the element from the front of queue.
    Input: None
    Output: None
    Return value: None
    */
    if( !isEmpty() ){
	count--;
	if(front==rear)
		front=rear=-1;
	else
		front = (front+1)%capacity;
    }
}

template<typename T>
T queue<T>::peek(){
    /*
    Objective: To find the front element of the queue.
    Input: None
    Output: None
    Return value: element at the front, if queue is not empty
                  NULL, if queue is empty
    */
    if( !isEmpty() )
        return arr[front];
}

template<typename T>
void queue<T>::queue_status(){
    /*
    Objective: To display the queue
    Input: None
    Output: Queue data
    Return value: None
    */
    cout<<"\n\n------------------------------Queue----------------------------------\n";
    int i=front;
    if(!isEmpty()){
	    if( front <= rear ){
		while(i<=rear)
			cout<<arr[i++]<<"\t";
	    }
	    else{
		while(i<capacity)
			cout<<arr[i++]<<"\t";
		i=0;
		while(i<=rear)
			cout<<arr[i++]<<"\t";
	    }
    }
    cout<<"\n--------------------------------------------------------------------";
}


int main(){
    /*
    Objective: To perform various circular queue operations.
    */
    int c;
    cout<<"\nEnter capacity of queue: ";
    cin>>c;
    queue<int> q(c);
    int choice;
    while(1){
    cout<<"\n\n\t\t\tQUEUE OPERATIONS\n\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.SIZE\n5.PRINT QUEUE\n6.EXIT\n\n";
    cout<<"\nEnter your choice : ";
    cin>>choice;
    switch(choice){
        case 1: if(!q.isFull()){
                cout<<"\nEnter element: ";
                q.enqueue(q.input());
            }
            else
                cout<<"\nQueue Full!!Cannot insert!!";
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
                cout<<"\nFront element: "<<q.peek();
            else
                cout<<"\nQueue is empty!!";
            break;
                
        case 4: cout<<"\nSize of queue: "<<q.size();
            break;
                
        case 5: q.queue_status();
            break;
                
        case 6: exit(0);
        
        default: cout<<"Invalid choice!!";
            break;
    }
    }
    return 0;
}

