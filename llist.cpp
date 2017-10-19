//INSTRUCTION:
//Use the provided text to help create llist.cpp
//based on Yoshii  CS311  Notes-6A

//- Make sure PURPOSE and PARAMETER comments are given
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  control-K cuts and control-Y pastes
//  Esc X replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW3P1 llist
//Your name: ** Dragan Lukic
//Complier:  ** g++
//File type: llist implementation file
//=====================================================

using namespace std;

#include<iostream>
#include"llist.h" 

/*Constructor
- initialize Front and Rear to be NULL and Count = 0.
- This does not create any node.  The new list is empty.
*/
  llist::llist()
   {
    Front = NULL;
     Rear = NULL;
    Count = 0;
   }
/*Destructor  
- while the list is not empty, call deleteFront repeatedly to delete all nodes.
- Please place a cout in this function "calling the llist desctructor."
*/
llist::~llist()
 {
el_t Num; 
 cout<< "Calling the llist deconstructor" << endl;
  while(!isEmpty())  //while the list is not empty,  
   {
    deleteFront(Num); //keep deleting nodes until it is empty
   }
}
bool llist::isEmpty()
//  - return true if Front and Rear are both pointing to NULL and Count is 0.
//  - (all 3 conditions must be checked)
{
 if( Front == NULL && Rear == NULL && Count ==0)
   {
     return true;
   }
  else
   {
    return false;
   }
}
void llist::displayAll()
//  - Special case: if the list is empty, display [ empty ] ).
//  - Regular: 
//    displays each element of the list horizontally starting from Front in [ ].
{  
 if(isEmpty())
  {
   cout << "[ empty ]"<< endl;
  }
 else
  {
    Node *P = Front; //place pointer at begging of the list 
     while(P !=NULL) //while pointer hasn't reached the end, display next element
      {
     
       cout << "[" << P->Elem << "]" << endl;
       P= P->Next;  //move pointer to next node
      }
    cout << endl;
 }
}
void llist::addRear(el_t NewNum) 
/*2 cases:
  - Special case: if this is going to be the very first node, you must
    create a new node and make Front and Rear point to it. Place NewNum and
    Count is updated.
  - Regular: adds a new node at the rear and puts NewNum in the Elem field
    of this new node. Count is updated.
    Regular case:
    Rear->Next = new Node;
    Rear = Rear->Next;
    Rear->Elem = NewNum;
    Rear->Next = NULL;
*/
{ 
 if(isEmpty())
   {
    Front = new Node;
    Rear = Front;
   }
   else
    {
      Rear->Next = new Node;
      Rear = Rear->Next;
    } 
      Rear->Elem = NewNum;
      Rear->Next = NULL;
   
    Count++;
  }

void llist::addFront(el_t NewNum)
/*2 cases:
- Special case: if this is going to be the very first node, you must
   create a new node and make Front and Rear point to it. Place NewNum and
   Count is updated.
- Regular: add a new node to the front of the list and 
  Count is updated.
  Regular case:
  Node *x;
  x = new Node;
  x->Next = Front;
  Front = x;
  Front->Elem = NewNum;
*/
{
 if(isEmpty())//makes sure that it's empty
  {
   Front = new Node;//creating first node
   Front->Elem =NewNum; 
   Front->Next=NULL; //makes sure that front->elem isnt pointed to anything
   Rear=Front; //setting front and rear to point to the same thing
  }
 else
  {
    Node *x; //makes a new temporary node, next
    x = new Node;
    x->Next = Front;
    Front = x;
    Front->Elem = NewNum;
  }
 Count++;
}
void llist::deleteFront(el_t& OldNum)
/*3 cases:
- Error case: if the List is empty, throw Underflow
- Special case: if currently only one Node,
   give back the front node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the front node element through OldNum (pass by reference)
  and also removes the front node.  Count is updated.
  Regular case:
  OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
*/
{
 if(isEmpty()) //if empty,throw underflow
  {
   throw Underflow();
  }
 else if(Count==1) //else if there's only one element 
  {
   OldNum= Front->Elem; //set OldNum to front element
   delete Front; //delete front element
   Front = NULL;  //set front to Null
   Rear = NULL;  //set Rear to NULL
  Count--; //update count by decremebting
 }
else  //else if there is more than one element
 {
   OldNum = Front->Elem;
  Node *Second;
  Second = Front->Next;
  delete Front;
  Front = Second;
  Count--;
 }
}


void llist::deleteRear(el_t& OldNum)
/* 3 cases:
- Error case: if empty, throw Underflow
- Special case: if currently only one node,
   give back the rear node element through OldNum (pass by reference) and
   make sure both Front and Rear become NULL. Count is updated.
- Regular: give back the rear node element through OldNum (pass by reference)
  and also remove the rear node. Count is updated.
  Regular case:
  OldNum = Rear->Elem;
  Node *p;
  Make p go to the one right before rear (using while)
  delete Rear;
  Rear = p;
*/
{
 if(isEmpty()) //if it's empty, throw underflow
  {
   throw Underflow();
  }
 else if(Count ==1) //else if there is only one node
  {
   
   OldNum= Rear->Elem; //set OldNum to the rear element
   delete Rear; //delete rear
   Front = NULL; //set front to null
   Rear = NULL; // set rear to null
   Count--; //update count by decrementing
  }
 else //else if there is more than one node
 {
   OldNum = Rear->Elem;
  Node *p =Front;
 // Make p go to the one right before rear (using while)
  while(p->Next !=Rear) //while we haven't reached the end, yet
   p=p->Next; //keep going down the list, until rear has been reached
 delete Rear; //delete rear
  Rear = p; // make p the new user
  Rear->Next = NULL; // make p Null
  Count --; //decrement 
 }
}   
void llist::deleteIth(int I, el_t& OldNum)
/*4 cases:
- Error case: 
  If I is an illegal value (i.e. > Count or < 1) throw OutOfRange.
- Special cases: this should simply call deleteFront when I is 1 or 
  deleteRear when I is Count
- Regular: delete the Ith node (I starts out at 1).  Count is updated.
<see the template loops in the notes to move 2 pointers to the right nodes;
and make sure you indicate the purposes of these local pointers>
*/
{
 if( I>Count || I<1)
  {
   throw OutOfRange();
  }
 else if(I== 1)
  {
   deleteFront(OldNum);
  }
 else if(I == Count)
  {
   deleteRear(OldNum);
  }
 else
  {
   Node *p = Front; //set to front 
   Node *j = Front->Next;
  for (int i = 1; i<=I-1; i++)
   {
    p=p->Next;
    j= j->Next;
   }
  p->Next = j->Next;
  OldNum = j->Elem;
  delete j;
  Count--;
 }
}
void llist::addbeforeIth(int I, el_t newNum)
/*4 cases:
-  Error case:
   If I is an illegal value (i.e. > Count+1 or < 1) throw OutOfRange.
-  Special cases: this should simply call addFront when I is 1 or addRear when
   I is Count+1
-  Regular: add right before the Ith node. Cout if updated.
<see the template loops in the notes to move 2 pointers to the right nodes
and make sure you indicate the purposes of these local pointers>
*/
{
 if(I>Count+1 || I< 1)
  {
   throw OutOfRange();
  }
 else if(I == 1)
 {
  addFront(newNum);
 }
else if(I==Count+1)
 {
  addRear(newNum);
 }
else
 {
  Node *p = Front;
  for( int i =1; i<=I-1; i++) //move through list
   {
    p=p->Next;
   }
  Node *temp = p->Next;
 p->Next = new Node;
 p->Next->Next = temp;
p->Next->Elem = newNum;
 Count++;
}
}
