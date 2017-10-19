//INSTRUCTION
//Look for 
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 queue
//Your name: Dragan Lukic
//Complier:  g++
//File type: .cpp file
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// constructor 
queue::queue()
{
count = 0;
front = 0;
rear = -1;
}

//destructor 
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
if(count==0)
 return true;
  else return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
if(count==MAX_SIZE)
 return true;
 else return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear 
// PAREMETER: provide the element (newElem) to be added
void queue::add(el_t newElem)
{
if(isFull())
 throw Overflow();
else
 {
  rear = (rear+1) % MAX_SIZE;
  el[rear]= newElem;
  count++;
 }
}
// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back 
// PARAMETER: provide a holder (removedElem) for the element removed (pass by ref)
void queue::remove(el_t& removeElem)
{
 if(isEmpty())
   throw Underflow();
else
 removeElem =el[front];
 front = (front +1)% MAX_SIZE;
 count--;
 
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
//PARAMETER: provide a holder (theElem) for the element (pass by ref)
void queue::frontElem(el_t& theElem)
{
 if(!isEmpty())
 theElem= el[front];
  else
   throw Underflow();
}

// PURPOSE: returns the current size to make it 
// accessible to the client caller
int queue::getSize()
{
 return count;
}

// PURPOSE: display everything in the queue horizontally from front to rear
// enclosed in []
// if empty, displays [ empty ]
void queue::displayAll()
{
 if(!isEmpty())
  {
    int j =front; //set front to our new variable
    
    for( int i = 0; i <count; i++) //goes through each elelemnt in our queue
     {
      j= j%MAX_SIZE; //make sure we find the elements needed
      cout << el[j] << endl; //display element
     j++;
     }
}
 else cout << "[empty]" << endl;
}

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear by
//doing remove followed by add.
void queue::goToBack()
{// ** comment a local variable
if(isEmpty())
 {
   throw Underflow();//if empty, throw underflow
 }
 else if(count ==1)
   {
    cout << endl;
   }
 else
  {
   el_t back;
   remove(back);
   add(back);
  }
}




