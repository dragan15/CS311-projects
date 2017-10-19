//INSTRUCTION
//Look for ** to complete this program 
//The output should match my hw1stackDemo.out 

//=========================================================
//HW#: HW1P1 stack
//Your name: Dragan Lukic
//Complier:  g++
//File type: client program
//===========================================================

using namespace std;

#include <iostream>
#include <string>
#include "stack.h"

//Purpose of the program: the purpose of the program is to calculate postfix expressions
//Algorithm: the algorithm involves using a while loop to check each characterm and nake sure it's either an operand or an operator, then adds the operands to the stack. for each operator, two operands are removed and the results are pushed back into the stack
int main()
{
  stack postfixstack;  // integer stack
  string expression;   // user entered expression
  
  cout << "type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // character position within expression
  char item;  // one char out of the expression
  
  int box1;  // receive things from pop
  int box2;  // receive things from pop
  
  while (expression[i] != '\0')
    {
      try
	{
	  item = expression[i];  // current char
	  
	  //2.  if it is an operand (number), 
	  //    push it (you might get Overflow exception)
	  // ** 
	  if(isdigit(item))
           {
            if(!postfixstack.isFull())
             {
              postfixstack.push(item- '0');
             }
           }
	  //3.  else if it is an operator,
	  //    pop the two operands (you might get Underflow exception), and
	  //	apply the operator to the two operands, and
	  //    push the result.
	 
          
	 else if ( (item == '+') || (item == '-') || (item == '*'))
	    { 
              int result;
	      postfixstack.pop(box1);
	      postfixstack.pop(box2);
	      //cases for different operators follow:
	      if (item == '-') result = box2-box1;
	      else if(item == '+') result = box2+box1;
              else if(item == '*') result = box2*box1;
                postfixstack.push(result);		
	      // ** also do the + and * cases 
	      // ** Finally push the result
	    }
	  else throw "invalid item";
	} // this closes try
      
      // Catch exceptions and report problems and quit the program now. 
      // Error messages describe what is wrong with the expression.
      catch (stack::Overflow) 
	{cout << "Error, too many operands(numbers) in your expression" << endl; return 0; }
      catch (stack::Underflow) // for too few operands
	{cout << "Error, too FEW operands(numbers) in your expression" << endl; return 0; }
      catch (char const* errorcode) // for invalid item
	{cout << "Error Invalid character. Please only use numbers and operator" << endl; return 0; }
      // go back to the loop after incrementing i
      i++;
    }// end of while
  
  // After the loop successfully completes: 
  // The result will be at the top of the stack. Pop it and show it.
   //**
  // If anything is left on the stack, an incomplete expression was found.
  // Inform the user.
   //**
int result;
 if(!postfixstack.isEmpty())
   {
    postfixstack.pop(result);
    if(postfixstack.isEmpty())
     {
      cout<< "result is " << result << endl;
     }
   else
    {
     cout << "Error, incomplete expression. not enough operators for operands" << endl;
   }
  }

}// end of the program

