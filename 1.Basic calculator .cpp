// File Name: program1.cpp
// Author: Hamza Tanveer
// Student ID: W836B668
// Assignment Number: 1
// Description: Displays the sum, difference, product or quotient of two
// integers entered by the user. Does not attempt to divide by zero
// Last Change: June 12,2017


#include <iostream>
using namespace std;
int main (void)

{
	int first_integer, second_integer, total, operation;

	cout << "\n" << " Calculate the sum, difference, product or quotient of two integers.\n"
	     << "Enter the first integer: ";
	cin  >> first_integer;
	cout << "Enter the second integer: ";
	cin  >> second_integer;




	cout << " The available operations are: \n"
	     << "\t1. addition\n"
	     << "\t2. subtraction\n"
	     << "\t3. multiplication\n"
	     << "\t4. division\n"
	     << "Enter the number for you choice of operation: ";
	cin >> operation;




	if (operation <=4)
	{
		if(operation == 1)
		   {
			total = first_integer + second_integer;
			cout << " \t your answer = " <<total << endl;
		   }

		 if(operation == 2)
		   {
 			total = first_integer - second_integer;
			cout<< "\t your answer = " << total << endl;
		   }

		 if(operation == 3)
		   {
			total = first_integer *
			second_integer;
			cout << "\t your answer = " << total << endl;
		   }

		 if(operation == 4)
		   {

			while(second_integer == 0) // loop created, allowing user to enter non-zero second_integer for the operation to work
			{
				cout << "\t " << first_integer << "/ 0 can not be found because can't divide by zero.\n"
				     << "Please re-enter a second integer which is not zero" << endl
				     << " = ";
				cin  >> second_integer;
			}
		  	total = first_integer / second_integer;
			cout << "\t your answer = " << total << endl;

		   }
	}
	else
	{
		cout <<operation
		     << " is an invalid operation. Valid choices were 1,2,3 or 4. Quitting Program\n";
	}


	return 0;
}
