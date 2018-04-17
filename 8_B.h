//Function definitons for different types of traversals on binary tree - INORDER, PREORDER, POSTORDER

#include<iostream>
using namespace std;

void inorder(TNode* p)
{
  /*
  Objective : To perform in-order traversal on BST 
  Input: p -> root of the subtree currently being tranverse
  Output: In-order tranversal of BST
  Approach: Recursion
  */
 
    if(p != NULL)
    {
        if(p->left) inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right) inorder(p->right);
    }
    else return;
}

void preorder(TNode* p)
{
  /*
  Objective : To perform pre-order traversal on BST 
  Input: p -> root of the subtree currently being tranverse
  Output: Pre-order tranversal of BST
  Approach: Recursion
  */
 
    if(p != NULL)
    {
        cout<<" "<<p->data<<" ";
        if(p->left) preorder(p->left);
        if(p->right) preorder(p->right);
    }
    else return;
}

void postorder(TNode* p)
{
  /*
  Objective : To perform post-order traversal on BST 
  Input: p -> root of the subtree currently being tranverse
  Output: Post-order tranversal of BST
  Approach: Recursion
  */
 
    if(p != NULL)
    {
        if(p->left) postorder(p->left);
        if(p->right) postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else return;
}


