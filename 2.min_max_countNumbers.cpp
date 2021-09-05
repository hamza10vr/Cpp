// File Name: program2.cpp
// Author: Hamza Tanveer
// Student ID: W836B668
// Assignment Number: 2
// Description: Prompts the user to enter some numbers and finds the minimum, maximum, and count (number) of the entered numbers
// separately for the positive and negative numbers.  It then prints out this informa-tion in the format shown below.
//  Entering 0 should terminate the input sequence and cause the results to be displayed
// Last Change: June 21,2017




#include <iostream>
using namespace std;
int main (void)

{
	double number = 0.000;
	double positive_max = 0.000;
	double positive_min = 0.000;
	double negative_max = 0.000;
	double negative_min = 0.000;
	int positive_count = 0;
	int negative_count = 0;
	
	// numbers with fractions displayed with 3 places after decimal points
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision (3);
	
	cout << "Entering 0 will terminate the sequence of input values\n";
	cout << "Enter a number: ";	 
	cin  >> number;
	
	
	
	while (number != 0)		// loop will keep on executing until the user enters the number zero
	{			
		if (number > 0)		// everytime user inputs number > 0, then increase the positive counter by 1. To keep track of how many positive numbers were entered
		{
			positive_count++;
			
			
			if (number >positive_max) 	// if number > positive_max then make the new number = positive_maximum
			{
				positive_max = number;
			}
			if ((number < positive_min) || (positive_min == 0))		// if the entered number < positive_minimum  or the positive_minimum = zero then make the new number = positive _minimum
			{
				positive_min = number;
			}
		}
		else if (number < 0) 	// if user inputs number < 0, then increase the negative counter by 1. To keep track of how many negative numbers were entered
		{
			negative_count++;
			
			
			if ((number > negative_max) || (negative_max ==0))		// if the entered number > negative_max  or the negative_max = zero then make the new number = negative _minimum
			{
				negative_max= number;
			}
			if (number < negative_min) 		//if number less than negative_minimus then make the new number negative_minimum
			{
				negative_min = number;
			}
		}
		
	cout << "Enter a number: ";	 
	cin  >> number;	
	
	}
	
		
	
	
	// if positive counter > 0 then output the max and min of positive numbers 
	if (positive_count > 0) 
	{	
		cout << endl;  // endl added to make blank lines and spaces between the answers. 
		cout << "There were " << positive_count << " positive values entered,"
			 << " with minimum " << positive_min << ", maximum " << positive_max << ". \n";
		cout << endl;
	}	
		else  	// if positive_counter == 0, tell the user no positive numbers were entered	
		{
			cout << endl;
			cout << "no positive numbers were entered \n";
			cout << endl;
		}

	
	//	if negative counter > 0 then output the max and min of negative numbers 
	if (negative_count > 0)	
	{	
		cout << "There were " << negative_count << " negative values entered,"
		     << " with minimum " <<  negative_min << ", maximum " << negative_max << ". \n";
		cout << endl;
	}
		else 	// if negative_counter = 0, tell the user no negative numbers were entered
		{	
			cout << "no negative numbers were entered \n";
			cout << endl;
		}
	
		
	
	
	return 0;
}
