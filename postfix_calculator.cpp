/*
	postfix_calculator.cpp

	Alex Patel

	For CSCI 262, Spring 2014, Assignment 2.

	Implementation of the postfix calculator.  You should modify the code
	everywhere you see a "TODO" comment!

	http://cse.csusb.edu/dick/samples/stl.html
	// used tpo reference the STL stack

	http://www.youtube.com/watch?v=zla7ha0OORM
	// used for RPN help
*/

#include "postfix_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <cstdlib>

using namespace std;


stack <double> calcStack;



bool postfix_calculator::evaluate(string expr) {
	// TODO: Implement as per postfix_calculator.h
	//
	// Read the comments in postfix_calculator.h for this
	// method first!  That is your guide to the required
	// functioning of this method.
	//
	// There are various ways to parse expr.  I suggest
	// you create an istringstream object, constructed on
	// expr:
	// 	istringstream string_in(expr);
	// Then you can get each substring from expr using >>.
	// You can determine which of the substrings represent
	// numbers using the to_double function provided below.


	double num, num2; // variable to store contents of the string
	if( istringstream(expr) >> num >> num2 )
	{
		calcStack.push(num); // push the number onto the stack
		calcStack.push(num2); // push num2 onto the stack
	}
	

	// Check to see if the input is a valid operator

	//p1 = calcStack.top(); // p1 is the number on the top of the stack
	//calcStack.pop(); // pop off p1

	//p2 = calcStack.top(); // p2 is the next number on the stack
	//calcStack.pop(); // pop off p2

	cout << num << endl << num2 << endl;
	


	// (+) operator
	if(expr == "+")
	{
		add(p1,p2);
	}

	// (-) operator
	else if(expr == "-")
	{
		sub(p1,p2);
	}

	// (*) operator
	else if(expr == "*")
	{
		mult(p1,p2);
	}

	// (/) operator
	else if(expr == "/" )
	{
		divide(p1,p2);
	}


	//cout << result << endl;
	//calcStack.push(result); // push the result onto the stack

	return true;
}



// TODO: Implement the remaining functions specified
// in postfix_calculator.h (except for to_double(), 
// which is done for you below).
//
// You should start by creating "stubs" for each of
// the methods - these are methods that do nothing
// except return a value if needed.  For example, the 
// evaluate() method above does nothing but return true.
//
// Once you've got stubs for everything, then you should
// be able to compile and test the user interface.  Then
// start implementing functions, *testing constantly*!


// Clear function
// clears any error conditions and also empties the stack
void postfix_calculator::clear()
{
	//empty the stack
	if(calcStack.empty() == false) // if the stack isn't empty
	{
		int i = 0;
		while( i = ! calcStack.size() ) // 
		{
			calcStack.pop(); // pop the top off of the stack
		}
	}

	//clear error conditions
}

// Top function
// returns the top item on the stack(most recent evaluate() call)
double postfix_calculator::top()
{
	return calcStack.top(); 
}

// Invalid Operator Flag function
// return the status of the operator error flag
bool postfix_calculator::invalid_operator_flag(const std::string& expr)
{
	string operators[] = {"+", "-", "*", "/"};
	invalid_operator_string(expr);
	for(int i = 0; i < 4; i++)
	{
		if( expr == operators[i] )
		{
			return true; // it is a valid operator
		}
		
	}
	return false; // not a valid operator
}

std::string postfix_calculator::invalid_operator_string(const std::string& expr)
{
	return expr;
}

// Stack Underflow Flag function
// returns the status of the stack underflow error flag
bool postfix_calculator::stack_underflow_flag()
{
	return true;
}


// Constructor
postfix_calculator::postfix_calculator()
{

}


// Returns true and sets d to the first numerical value in s if
// a numerical value can successfully be extracted.  Returns false
// if unsuccessful (implying there is no numerical value).
bool postfix_calculator::to_double(const string &s, double &d) {
	istringstream cvt(s);
	cvt >> d;
	return !(cvt.fail()) && cvt.eof();
}
