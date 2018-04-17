//Structure and function definitions for implementation of binary search tree
 
#include<iostream>
using namespace std;

struct TNode { 
	/*   			
	objective: Create a structure for a Node for Binary Search Tree 
	input parameters: none
	output value: none
	description: TNode structure defines the node structure of BST
	*/
	  int data; 
	  TNode* left;
	  TNode* right; 
};

TNode* getNode(const int& e){

    /*
    Objective: To create a new object of structure TNode, initialize its members and return its pointer.
    Input: An integer
    Output: None
    Return value: A Pointer to the object of structure TNode.
    */
	TNode* temp = new TNode();
	temp->data = e;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

bool empty(TNode* root){

    /*
    Objective: To test whether the tree is empty.
    Input: root -> root node of the tree.
    Output: None
    Return value: true, if tree is empty
                  false, if tree is not empty.
    */
     return root==NULL;
}

void insert(TNode** root, int d)
{
    /*
    Objective: To insert a node in the binary search tree.
    Input: e -> The element to be inserted.
	   root -> pointer to the root node of the tree.
    Output: None
    Return value: None
    Side effect: A node is added to the tree.
    */
    TNode* t = getNode(d);
    if(empty(*root))
	 *root = t;
    else
    {
    	TNode* curr = *root;
	TNode* parent = NULL;
    	while(curr)
    	{
		parent = curr;
		if(t->data > curr->data) 
			curr = curr->right;
        	else 
			curr = curr->left;
    	}

   	if(t->data < parent->data)
       		parent->left = t;
    	else
       		parent->right = t;
    }
}

TNode* min_value_node(TNode* p)
{
    /*
    Objective : To find the minimum element in the subtree where p is the root.
    Input : p -> root of the subtree
    Output : none
    Return value : Node with the minimum value in the subtree.
    Approach : loop down to find the leftmost leaf  
    */

    while (p->left != NULL)
        p = p->left;
    return p;
}

TNode* remove(TNode** root, int ele){
 
    /*
    Objective : To remove a given element from the BST.
    Input : root -> pointer to the root node of the subtree.
	    ele -> element in this subtree which is to be deleted
    Ouput : None
    Return value : Pointer to the updated root
    Side effect : If a node with the given value found, it is deleted from the tree 
    */
    if (*root) { 
    
	    if (ele < (*root)->data)	// If the key to be deleted is smaller than the root's key, then it lies in left subtree
		(*root)->left = remove(&(*root)->left, ele);
	    else if (ele > (*root)->data)	// If the key to be deleted is greater than the root's key, then it lies in right subtree
		(*root)->right = remove(&(*root)->right, ele);
	    else			// if key is same as root's key, then this is the node to be deleted
	    {
		// node with only one child or no child
		if ((*root)->left == NULL)
		{
		    TNode *temp = *root;
		    *root = (*root)->right;
		    delete temp;
		}
		else if ((*root)->right == NULL)
		{
		    TNode *temp = *root;
		    (*root) = (*root)->left;
		    delete temp;
		}
	 
		// node with two children: Get the inorder successor (smallest in the right subtree)
		else{
			TNode* successor = min_value_node((*root)->right);
		        // Copy the inorder successor's content to this node
			(*root)->data = successor->data;
		 
			// Delete the inorder successor
			(*root)->right = remove(&(*root)->right, successor->data);
		}
	    }
    }
    return *root;
}

void display(TNode* root, int space=0){
  
   /*
	Objective : To print the binary tree in a structured manner
	Input : root -> Pointer to root of below tree
		space -> no. of spaces to be printed before printing the data of the root
              1
            /  \
           2    3 
          / \   / \
         4   5  6  7 

	Output : Tree structure as follows
		            7

		  3

		            6

	1

		            5

		  2

		            4
     Approach : Traverse the tree in reverse in-order and print rightmost element first and leftmost element in the end.
                Spaces are given according to the depth of the node which is to be printed.
  */

    if (root != NULL){

	    space += 1;
 	    display(root->right, space);
 	    cout<<endl;
    	    for (int i = 1; i < space; i++)
            	cout<<"          ";
    	    cout<<root->data<<endl;
  	    display(root->left, space);
   }
}

bool search(TNode* root, int ele){

	/*Objective : To check whether a data is present in the tree or not.
	  Input : root -> root node of the tree in which the data is to be searched.
		  ele -> the data to be searched.
          Ouput : none.
	  Return value : true, is data found.
			 false, otherwise.
        */  
	if(root){
		if(ele < root->data )
			return search(root->left, ele);
		else if(ele > root->data )
			return search(root->right, ele);
		else
			return true;
		
	}
	return false;
}
