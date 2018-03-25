#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

template <typename NT>
class SNode { 
	/*   			
	objective: Create a class for a Node for Single Linked list
	input parameters: none
	output value: none
	description: SNode class defines the node structure 
	approach: Class defines data item is names element with datatype string 
			and link is named next pf snode type
	*/
	private:
	  NT elem; 
	  SNode* next; 
	template <typename T>
	friend class SLinkedList; // provides SLinkedList access to SNode
};

template <typename T>
class SLinkedList { 
	/*   			
	objective: Create a Single LInked List class 
	input parameters: none
	output value: none
	side effects: Class SlinkedList defines Single Linked LIst class
	approach: Class definition
	*/						
	public:
	SLinkedList();							// empty list constructor
	~SLinkedList();							// destructor
	SNode<T>* getNode(T e);				// creates a new SNode and returns its pointer
	const T input();				// takes an input of type T
	bool empty() const; 					// is list empty?
	const T front() const; 			// get front element
	void addFront(const T e); 		// add to front of list
	void addBack(const T e); 			// add to back of list
	void removeFront();			 			// remove from front 
	void removeEnd();						// remove from end
	void print(); 							// prints the SLL
	private:
	SNode<T>* head; 							// pointer to the head of list
};

template <typename T>
SLinkedList<T>::SLinkedList(){

    /*
    Objective: To construct an object of class SLinkedList and initialize head with NULL.
    Input: None
    Output: None
    Return value: None
    */
    
	head = NULL;
}

template <typename T>
SLinkedList<T>::~SLinkedList(){
    
    /*
    Objective: To destruct the object of class SLinkedList.
    Input: None
    Output: None
    Return value: None
    */
    
	SNode<T>* curr = head;
	while(curr != NULL){
		SNode<T>* next = curr->next;
		delete curr;
		curr = next;
	}
	head = NULL;
}

template <typename T>
SNode<T>* SLinkedList<T>::getNode(T e){

    /*
    Objective: To create a new object of class SNode, initialize its members and return its pointer.
    Input: A string
    Output: None
    Return value: A Pointer to the object of class SNode.
    */
	SNode<T>* temp = new SNode<T>;
	temp->elem = e;
	temp->next = NULL;
	return temp;
}

template <typename T>
const T SLinkedList<T>::input(){
	T ele;
	cin>>ele;
	return ele;
}

template <typename T>
bool SLinkedList<T>::empty() const{

    /*
    Objective: To test whether the list is empty.
    Input: None
    Output: None
    Return value: true, if list is empty
                  false, if list is not empty.
    */
	if(head==NULL)
		return true;
	else
		return false;
}

template <typename T>
const T SLinkedList<T>::front() const{

    /*
    Objective: To return the front element of the list.
    Input: None
    Output: None
    Return value: element at the front, if list is not empty
                  NULL, if list is empty
    */
	if(!empty())
		return head->elem;
}

template <typename T>
void SLinkedList<T>::addFront(const T e){

    /*
    Objective: To insert a node at the front of list.
    Input: e -> The element to be inserted.
    Output: None
    Return value: None
    */

	SNode<T>* temp = getNode(e);
	if(head == NULL)
		head = temp;
	else{
		temp->next = head;
		head = temp;
	}
}

template <typename T>
void SLinkedList<T>::addBack(const T e){
    /*
    Objective: To insert a node at the end of list.
    Input: e -> The element to be inserted.
    Output: None
    Return value: None
    */
	SNode<T>* temp = getNode(e);
	if(head == NULL)
		head = temp;
	else{
		SNode<T>* t = head;
		while(t->next != NULL)
			t = t->next;
		t->next = temp;
	}
}

template <typename T>
void SLinkedList<T>::removeFront(){

    /*
    Objective: To remove a node from the front of list.
    Input: None
    Output: None
    Return value: None
    */
	if(!empty()){
		SNode<T>* temp = head;
		head = head->next;
		delete temp;
	}
}

template <typename T>
void SLinkedList<T>::removeEnd(){

    /*
    Objective: To remove a node from the end of list.
    Input: None
    Output: None
    Return value: None
    */
	if(!empty()){
		SNode<T>* curr = head;
		if(head->next == NULL)
			head = NULL;
		else{	
			SNode<T>* prev = curr;
			while(curr->next != NULL){
				prev = curr;		
				curr = curr->next;	
			}
			prev->next = NULL;
		}		
		delete curr;
	}
}

template <typename T>
void SLinkedList<T>::print(){
    
    /*
    Objective: To display the queue
    Input: None
    Output: Queue data
    Return value: None
    */
	cout<<"\n\n---------------------------------LIST-------------------------------------------\n";
	SNode<T>* curr = head;
	while(curr != NULL){
		cout<<curr->elem<<"\t";
		curr = curr->next; 	
	}
	cout<<"\n----------------------------------------------------------------------------------";
}

int main(){
    /*
    Objective: To perform various singly linked list operations.
    */
    
    SLinkedList<int> sll;
    int choice;
    while(1){
	    cout<<"\n\n\t\t\tLINKED LIST OPERATIONS\n\n1.INSERT AT FRONT\n2.INSERT AT END\n3.REMOVE FRONT\n4.REMOVE END\n5.SHOW FRONT\n6.PRINT LIST\n7.EXIT\n\n";
       	    cout<<"\nEnter your choice : ";
	    cin>>choice;
	    cin.ignore();
	    switch(choice){

		case 1: cout<<"\nEnter element to be inserted: ";
		        sll.addFront(sll.input());
		        sll.print();
		    	break;
		    
		case 2: cout<<"\nEnter element to be inserted: ";
		        sll.addBack(sll.input());
		        sll.print();
		    	break;
		
		case 3: if(!sll.empty()){
			   sll.removeFront();
		      	   cout<<"\nElement removed!";
		        }
		   	else
		        	cout<<"\nList empty!!Cannot remove node!!";
			sll.print();
		        break;

		case 4: if(!sll.empty()){
			   sll.removeEnd();
		      	   cout<<"\nElement removed!";
		        }
		   	else
		        	cout<<"\nList empty!!Cannot remove node!!";
			sll.print();
		        break;        

		case 5:	if(!sll.empty())
		        	cout<<"\nFront element: "<<sll.front();
		    	else
		        	cout<<"\nList is empty!!";
		    	break;
		        
		case 6: sll.print();
		    	break;
		        
		case 7: exit(0);
		
		default: cout<<"Invalid choice!!";
		    	 break;
	    }
    }
    return 0;
}


