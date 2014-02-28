/*
	postfix_calculator.cpp

	For CSCI 262, Spring 2014, Assignment 2.

	Implementation of the postfix calculator.  You should modify the code
	everywhere you see a "TODO" comment!
*/

#include "postfix_calculator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

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


// Returns true and sets d to the first numerical value in s if
// a numerical value can successfully be extracted.  Returns false
// if unsuccessful (implying there is no numerical value).
bool postfix_calculator::to_double(const string &s, double &d) {
	istringstream cvt(s);
	cvt >> d;
	return !(cvt.fail()) && cvt.eof();
}
