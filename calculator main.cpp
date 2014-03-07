/*
	calculator_main.cpp

	Alex Patel

	For CSCI 262, Spring 2014, Assignment 2.

	Provides the user interface for the postfix calculator.

	author: C. Painter-Wakefield
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include "postfix_calculator.h"
#include <stack>
using namespace std;



int main() {
	// Tests
	//t.push(10);
	//t.push(20);
	//t.push(30);
	//while( t.top() != NULL )
	//{
	//	//int top = t.top();
	//	cout << t.top() << endl;
	//	t.pop();
	//}


	
	postfix_calculator calc;
	string input;

	cout << "Welcome to the postfix calculator!" << endl;
	cout << "----------------------------------" << endl;
	while (true) {
		cout << "Input string:" << endl;
		getline(cin, input);
	
		if (input == "quit") {
			return 0;
		}
		/*else if (input == "clear") {
			calc.clear();
		}
		else if (input == "debug") {
			bool has_flags = false;
			cout << "DEBUG MODE:" << endl;
			if (calc.stack_underflow_flag()) {
				cout << "Stack underflow flag set." << endl;
				has_flags = true;
			}
			if (calc.invalid_operator_flag(input)) {
				cout << "Invalid operator flag set." << endl;
				cout << "Invalid operator: ";
				cout << calc.invalid_operator_string() << endl;
				has_flags = true;
			} 
			if (!has_flags) {
				cout << "No flags." << endl;
			}
			if (calc.stack_underflow_flag()) {
				cout << "Stack is empty." << endl;
			} else {
				cout << "Top of stack contains: " << endl;
				cout << calc.top() << endl;
			}
		}*/
		else {
			bool success = calc.evaluate(input);
			if (success) {
				cout << "answer: " << calc.top() << endl;
			} else if (calc.stack_underflow_flag()) {
				cout << "ERROR: Stack underflow." << endl;
			} else if (calc.invalid_operator_flag(input)) {
				cout << "ERROR: Unrecognized operator '";
				cout << calc.invalid_operator_string(input);
				cout << "'." << endl;
			} else {
				cout << "ERROR: Unknown error." << endl;
			}
		}

		cout << "----------------------------------" << endl;
	}


	system("pause");

	return 0;
}
