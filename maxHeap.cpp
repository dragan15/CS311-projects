//INSTRUCTION
//Look for
//Fill in the function body
//When done, compile queue.cpp to make sure it has no syntax errors

//=========================================================
//HW#: HW1P1 max Heap
//Your name: Dragan Lukic
//Complier:  g++
//File type: .cpp file
//===========================================================


#include <iostream>
#include "maxHeap.h"

using namespace std;
void MaxHeap:: swap(int *x, int *y)
 {
  int temp = *x;
  *x = *y;
  *y = temp;
 }

int MaxHeap::parent(int i)
 {
  return (i-1)/2;
 }

int MaxHeap::left(int i)
 {
  return (2*i +1); 
 }

int MaxHeap::right(int i)
 {
  return (2*i +2);
 }
bool MaxHeap::isLeaf(int i)
 {
  return(i >= size/2);
 }
void MaxHeap::siftup(int i) //while parent is less than new node, keep swapping until parent is greater than node
 {
  while(i > 0 && arr[parent(i)] < arr[i]) //while parent is less than new node
   {       
    swap(&arr[i], &arr[parent(i)]); //pop new node with parent node       
    i = parent(i);    
   }
 }

void MaxHeap::siftdown(int i)//push downward, swapping with parent until new nodeis greater than parent
  {
   while(!isLeaf(i)) 
    {
     int l = left(i);
     int r = right(i);
     int larger = (arr[l] > arr[r]) ? l : r;
     if(arr[i] >= arr[larger])
       break;
      swap(&arr[i], &arr[larger]);
      i = larger; 
    }
  }


MaxHeap::MaxHeap(int cap)  //constructor
{
  size =0; 
  capacity = cap;
  arr = new int[capacity]; 
}

int MaxHeap::getSize() //gets size of tree
 {
  return size; //returns size
 }

int MaxHeap::getMax() //find the max node
 {
   return arr[0];
 }

void MaxHeap::insert(int k) //insert node
 {
   if (size >= capacity)
     throw Overflow();
   int i = size;
   arr[i] = k;
   siftup(i);
   size++;
 }

int MaxHeap::extractMax()
 {
   if(size <= 0) throw Underflow();
   if(size == 1) return arr[--size];            
   int result = arr[0];    
   arr[0] = arr[--size];    
   siftdown(0);    
   return result;
 }

int MaxHeap::removeAt(int i)
 {
   if(i < 0 || size <= i) throw Underflow();
   if(size == 1) return arr[--size];            
   int result = arr[i];    
   arr[i] = arr[--size];    
   if(arr[i] < result) siftdown(i);    
   else siftup(i);
   return result;
 }

void MaxHeap::heapify(int *array, int len)
 {
   arr = array;    
   capacity = size = len;    
   int half = size/2 - 1;	// the index of the last internal node
   for(int i = half; i >= 0; i--)        
   siftdown(i);
 }
