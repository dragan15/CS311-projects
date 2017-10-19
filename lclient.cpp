//Look for ** to complete all of them
//The output should match my assingment sheet

//=========================================================
//HW#: HW3P1 llist
//Your name: Dragan Lukic
//Complier:  g++
//File type: client program (tester)
//===========================================================

using namespace std;

#include <iostream>
#include "llist.h"

void caseOne()
{
  cout << "CASE 1:------------------- " << endl;
  llist L;   // this is my list
  int x;  // to hold a removed element

  //1 check empty and report the result  
  cout << 1 << "Checks if it's Empty" <<endl;
 // **
  if(L.isEmpty())
   cout << "List is Empty" << endl;
    else
   cout << "List os not Empty" << endl;
  //2 display the list  
  cout << 2 << "Display List" << endl;
 // **
  L.displayAll();
   
  //3 add 4 integers 1,2,3,4    
  cout << 3 << "Add 1,2,3,4 to Rear" <<  endl;
 // **
    L.addRear(1);
    L.addRear(2);
    L.addRear(3);
    L.addRear(4);
  //4 display the list  
  cout << 4 << "display list" << endl;
 // **
L.displayAll();
  //5 remove from front twice (and display the elements removed)
  cout << 5 << "Remove from front twice"<< endl;
 // ** 
 L.deleteFront(x);
   L.deleteFront(x);
   
  //6 display the list
  cout << 6 <<"display the list" << endl;
 // **
  L.displayAll();
  //7 check empty and report the result 
   cout << 7 <<"checks if it's empty" << endl;
  // **
    if(L.isEmpty())
      {
      cout << "it's empty" << endl;
      }
    else
     {
      cout << "List is not empty" << endl;
     }
  //8 remove from the rear twice (display the element removed)
   cout << 8 << endl;
  // **
     L.deleteRear(x);
      cout << x << "was deleted" << endl;
     L.deleteRear(x);
      cout << x << "was deleted" << endl;
  //9 check empty again and report the result
   cout << 9 << "checks if it's empty" << endl; 
 // **
  if(L.isEmpty())
   {
    cout << "It's Empty" << endl;
   }
  else
  {
   cout << "It's not empty" << endl;
  }
}//end of case 1 
 
void caseTwo()
{ 
  cout << "Case 2: -----------------------" << endl;
  llist L2;  // another list
  int x;   // to hold the removed element 
  int c = 1;  // displayed step number

  // 1.add to front once   (element 5)
  cout << c <<"add front: 5"<< endl; c++;
 // **
L2.addFront(5);
  // 2.add to front again  (element 4)
  cout << c <<"add front: 4" << endl; c++;
 // **
  L2.addFront(4);
  // 3.delete Front
  cout << c << "Delete front: " << endl; c++;
 // **
   L2.deleteFront(x);
  // 4.add to rear 3 times (elements 6,8,9)
  cout << c <<"add elements 6,8,9 to rear" <<  endl; c++;
  //**
  L2.addRear(6);
  L2.addRear(8);
  L2.addRear(9);
  // 5. display all
  cout << c <<"Display list" << endl; c++;
//  **
   L2.displayAll();
  // 6.add before the 1st  (element 4) . 4 5 6 8 9
  cout << c <<"add before 4th element" << endl; c++;
 // **
  L2.addbeforeIth(1,4);
  L2.displayAll();
  // 7.add before the 4th  (element 7) . 4 5 6 7 8 9
  cout << c <<"adding before 4th element"<< endl; c++;
 // **
  L2.addbeforeIth(4,7);
 L2.displayAll();
  // 8.add before the 7th  (element 10) . 4 5 6 7 8 9 10
  cout << c <<"add before 7th elem"<<  endl; c++;
  //**
   L2.addbeforeIth(7,10);
   L2.displayAll();
  // 9.add before the 9th  (element 12) . error (out of range)
  cout << c << "add before the 9th elem" << endl; c++;
  try{L2.addbeforeIth(9,12); } 
  catch(llist::OutOfRange){cout <<"Error, out of range" << endl;}
  // 10.add before the 0th (element 0) . error (out of range)
  cout << c <<"add before 0th element" << endl; c++;
  try{L2.addbeforeIth(0,x); } 
  catch(llist::OutOfRange){cout << "Error, out of range" << endl;}
  // 11.displayAll
  cout << c <<"display list" << endl; c++;
  //**
    L2.displayAll();
  // 12.delete Ith I==1 (indicate  the element removed) . 5 6 7 8 9 10
  cout << c <<"Delete first  element" << endl; c++;
  //**
   L2.deleteIth(1,x);
     cout << x << "was deleted" << endl;
  // 13.delete Ith I==6 (indicate the element removed)  - 5 6 7 8 9 
  cout << c <<"delete 6th element" <<  endl; c++;
 // **
  L2.deleteIth(6,x); 
    cout<< x << "was deleted" << endl;
  // 14.delete Ith I==3 (indicate the element removed)  - 5 6 8 9
  cout << c <<"delete 3rd element" << endl; c++;
 // **
   L2.deleteIth(3,x);
     cout << x << "was deleted" << endl;

  // 15.delete Ith I==5 . error (out of range)
  cout << c <<"delete 5th element" << endl; c++;
  try {L2.deleteIth(5,x); }
  catch(llist::OutOfRange){cout <<"Error, out of Range" << endl; }
  // 16.delete Ith I==0 . error (out of range)
  cout << c <<"deleting 0th element" << endl; c++;
  try {L2.deleteIth(0,x);}
  catch(llist::OutOfRange){cout<< "Error, out of range" << endl;}
  // 17.displayAll
  cout << c <<"displa all"<< endl; c++;
  //**
   L2.displayAll();
  // 18.delete from rear until it is empty (indicate the elements removed)
  cout << c << endl; c++;
  //**
   while(!L2.isEmpty())
    {
      L2.deleteRear(x);
     cout<< x << "was deleted" << endl; 
    }
  // 19.displayAll  
  cout << c <<"display all" << endl; c++;
 // **
  L2.displayAll();

}//end of case 2

void caseThree()
{
  cout << "Case 3:-------------------- " << endl;
  llist L3;
  int x;  // to hold the removed element

  // 1.add before the 0th . error (out of range)
  cout << 1 <<"add before 0th element" << endl;
  try {L3.deleteIth(0,x);}
  catch (llist::OutOfRange){cout<< "Error, out of range"<< endl;}
  //2.delete front . error (underflow)
  cout<< 2 <<"deleting front "<< endl;
  try {L3.deleteFront(x);}
  catch (llist::Underflow){cout << "Error, underflow" << endl;}
}   //end of case 3

void caseFour()
{
  cout << "Case 4:------------------------ " << endl;
  llist L4;
  int x;  // to hold the removed element

  //   1.delete 2nd . error (out of range)
  cout << 1 <<"delete 2nd element" << endl;
  try {L4.deleteIth(2,x);}
  catch (llist::OutOfRange){cout<< "Error, out of range" << endl;}
  //    2.delete rear . error (underflow)
  cout << 2 <<"delete rear" << endl;
  try {L4.deleteRear(x); }
  catch (llist::Underflow){cout<< "error, undeflow" << endl;}
} // end of case 4


//PURPOSE of the Program: **
//Algorithm/Design: 4 test cases are divided into 3 functions and **
int main()
{
  int selection; // this will indicate what the user wants to do
  
  do
  {
	cout << endl << "MENU: These are your options: " << endl << endl;
	cout << "   (1) Case 1  " << endl;
	cout << "   (2) Case 2  " << endl;
	cout << "   (3) Case 3  " << endl;
	cout << "   (4) Case 4 " << endl;
	cout << "    Enter ( 0 ) to quit " << endl;
	cout << "===>";
      
	cin >> selection;
      
    switch(selection)
	{
		case 1: caseOne(); break;
		case 2: caseTwo(); break;
		case 3: caseThree(); break;
		case 4: caseFour(); break;
	}
  }
  while(selection !=0);

}// end of main


