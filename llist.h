//INSTRUCTION:
//Llist class - header file template (by Yoshii) based on Notes-6A
//You must complete the ** parts and then complete llist.cpp
// Don't forget PURPOSE and PARAMETERS 
// =======================================================
// HW#: HW3P1 llist
// Your name: Dragan Lukic
// Compiler:  g++ 
// File type: headher file 
//=======================================================

//----- Globally setting up the alias and struct  ----------------
typedef int el_t ;  // elements will be **

//a list node is defined here as a struct Node
// I could have done class Node and add the data members under public
// but it would use too much space
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
  //**
    //purpose: check if list is empty
  bool isEmpty();
    
  //**
 //displays all elements in all the nodes
  void displayAll();

  //**
//addes a new node with the elemnt to the rear of the list
  void addFront(el_t);
    
  //**
// add an element to the front of the list
  void addRear(el_t);

  //**
    // delet front node and element
  void deleteFront(el_t&);
    
  //**
// delet back node and element
  void deleteRear(el_t&);
    
  //**
//delete the specified node and element
  void deleteIth(int, el_t&);

  //**    
//add element before the specified element
  void addbeforeIth(int, el_t);
    
};
