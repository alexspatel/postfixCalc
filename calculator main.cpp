/*
	postfix_calculator.cpp

	Alex Patel

	For CSCI 262, Spring 2014, Assignment 2.

	Implementation of the postfix calculator.  You should modify the code
	everywhere you see a "TODO" comment!

	http://cse.csusb.edu/dick/samples/stl.html
	// used tpo reference the STL stack
*/

#include "postfix_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <cstdlib>

using namespace std;

stack <int> s;

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

	std::string p1_str;
	std::string p2_str;
	std::string op;
	int p1, p2;

	istringstream string_in(expr);
	
	expr.substr();
	/**********************************************************************************/ // PRODUCES STRING ERROR
	// store the operands of expr
	for(int i = 0; i < sizeof(expr); i++)
	{
		expr >> p1_str >> p2_str >> op;
	}
	/**********************************************************************************/
	// convert from string to double
	str_to_num(p1_str);
	str_to_num(p2_str);
	
	
	// (+) operator
	if(op == "+")
	{
		add(p1,p2);
	}

	// (-) operator
	else if(op == "-")
	{
		sub(p1,p2);
	}

	// (*) operator
	else if(op == "*")
	{
		mult(p1,p2);
	}

	// (/) operator
	else if(op == "/" )
	{
		divide(p1,p2);
	}

	return true;
}

// Converts a string to a double
double postfix_calculator::str_to_num(const std::string p_str)
{
	stringstream convert(p_str); // conversion initialized with contents of p_str
	double p; // number containing the result

	if( !(convert >> p) ) // give the value to p using chars in the string
	{
		p = 0; // if that fails, set p to 0
	}
	return p;

	/*stringstream ss(p_str);
	double p;
	return ss >> p ? p : 0;*/
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
	if(s.empty() == false) // if the stack isn't empty
	{
		int i = 0;
		while( i = ! s.size() ) // 
		{
			s.pop(); // pop the top off of the stack
		}
	}

	//clear error conditions
}

// Top function
// returns the top item on the stack(most recent evaluate() call)
double postfix_calculator::top()
{
	return s.top(); 
}

// Invalid Operator Flag function
// return the status of the operator error flag
bool postfix_calculator::invalid_operator_flag()
{
	return true;
}

std::string postfix_calculator::invalid_operator_string()
{
	string boo = "Hi";
	return boo;
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
