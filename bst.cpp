// =======================================================
// HW#: HW4 BST
// Your name: Dragan Lukix
// Compiler:  g++ 
// File type: headher file 
//=======================================================
#include <iostream>
#include "bst.h"

using namespace std;

BST::BST() 
{
  root = NULL; //start with an empty tree
}
BST::~BST() //destroy the tree
{  //////////////////   
preorder(root);
  root=NULL;
}
        
void BST::insert(int data) 
{	//////////////////
  root = insert(root, data);
} 

Node* BST::insert(Node* node, int data) 
  {   //////////////////
     if(node == NULL)  //if tree is empty, add new node as root node
       {
         node = new Node(data);
       } else if(node->key > data) //if key is less than the root, add new node to left subtree
          {
            node->left = insert(node->left, data);
          } 
            else if(data > node->key) //if key is greater than root, add new node to right subtree
          {
            node->right = insert(node->right, data);
          }
	 return node;
  } 
void BST::preorder(Node *root) 
{
    if (root != NULL)
    {
        preorder(root->left);         // visit left sub tree 
        preorder(root->right);       //  visit right sub tree
        delete root;                  //  deletes root
    }
}


Node* BST::search(int key) 
 {//////////////////
  return search(root,key);
 }

Node* BST::search(Node* root, int key) 
  { //////////////////
   if (root == NULL || root->key == key) //if equal, search is successful, return root 
      return root;
   if (root->key < key) //if not, search right of subtree/ search left of subtree
    return search(root->right, key);
    return search(root->left, key);
  }

void BST::inorder() 
 {//////////////////
    cout << "Elements in the IN order: " << endl;
    inorder(root);  // start in-order traversal from the root
 }
void BST::inorder(Node* root) 
  {  //////////////////
    if (root != NULL) //if not empty
      {
        inorder(root->left);// traverse left subtree by recursively calling inorder function
        cout  <<  root->key<< endl;
        inorder(root->right);//traverse right subtree by recursively calling inorder function.
      }

  }
		
void BST::remove(int key)
  { //////////////////
    root= remove(root,key);
  }

Node* BST::remove(Node* node, int key)
  { //////////////////
   if (node == NULL)// if node that needs to be deleted is a leafe, remove the tree
     return node;
   if (node->key > key)
     node->left = remove(node->left, key);
   else if (key > node->key)
     node->right = remove(node->right, key);
   else
    { //has one child, copy child to node and delete child
     if (node->left == NULL) 
      {
        Node *temp = node->right; 
       delete node;
       return temp;
      }
     else if (node->right == NULL)
      {
        Node *temp = node->left;
        delete node;
        return temp;
      }  //node with two children. Get leftmost node(largest node on left subtree) from left subtree, and delete it.
      Node* temp = leftmostNode(node->left);
      node->key = temp->key;
      delete node->left, temp->key;
     node->left = node->left, temp->key;
    }
   return node;
  }




	
Node* BST::leftmostNode(Node* node)
  {//////////////////
    Node* current = node;
    node = node->left; //start with left
     /* loop down to find the leftmost leaf */
    while (current->right != NULL)
     {
       current = current->right;
     }
      
     return current;
 }




     
