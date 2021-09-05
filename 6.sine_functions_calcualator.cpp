/*  File Name: program6.cpp
 *  Author: Hamza Tanveer
 *  Student ID: w836b668
 *  Assignment Number: 6
 *  Description: This program uses an array of numbers to store pre-calculated
 *				values of the sine function of certain values, can then display
 *				valuse of various different formulas further calculated from 
 *				the stored values.
 *  Last Change: July 17, 2017
 */


#include <iostream>
#include <cmath> // sine
#include <iomanip>	// setw
using namespace std;
				
void fill_array(double array[]);
//values of the array elements mst be set to the sine of their index, eg
// eg. sine_values[0] is  set to sin(0 etc...

void x_y_formatting();
// formatting of x and y variables


const int SIZE = 20; 	// constand called size ( set to the value of 20)






int main ()
{			
	double sine_values[SIZE];
	double a, b ;
	
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);
	
	
	fill_array(sine_values);
	
	int choice;
	
	do
	{
		
		// the program displays a menu of choices to the user, accept their selection from the menu and respond
		cout << "formulas for which you can display values: \n"
			 << "\t 1. y = a sine(x)\n"
			 << "\t 2. y = sine(x) + b \n"
			 << "\t 3. y = a sine(x) + b \n"
			 << "\t 4. y = Quit \n"
			 << "Enter the number of your choice: ";
		cin  >> choice;
		
		
		switch(choice)
		{
			case 1:
				cout << endl << "Enter the value of a: ";
				cin >> a;
				
				x_y_formatting();								// prints x and y and the formatting for it
		
				for (int i(0); i < SIZE; i++)					// calculates the value of "y" by multiplying "a" to the value of sin(x)
				{												// fill in the array from [0] to [19]
					cout << setw(5) << i 
						 << setw(12) << a * sine_values[i]  	// y = a sin(x) 
						 << endl;
				}	
				
				cout << endl;									// to add a new line after the array, to make it easy to read
		break;
		
		case 2:
				cout << endl << "Enter the value of a: ";
				cin  >> a;
				cout << "Enter the value of b: ";
				cin  >> b;
				
				x_y_formatting();								// prints x and y and the formatting for it
				
		
				for (int i(0); i < SIZE; i++)					//calculates the value of "y" by calculating sin(x) then adding b
																// fill in the array from [0] to [19]
				{	
					cout << setw(5)  << i 
						 << setw(12) << sine_values[i] + b 		// y = sin(x) +b
						 << endl;
				}
				
				cout << endl;									// to add a new line after the array, to make it easy to read
		break;
		
		case 3:
				cout << endl << "Enter the value of a: ";
				cin  >> a;
				cout << "Enter the value of b: ";
				cin  >> b;
				
				x_y_formatting();										// prints x and y and the formatting for it
		
				for (int i(0); i < SIZE; i++)							// calculates the value of "y" by multiplying "a" to the value of sin(x) and then adding the balue of "b" to it
																		// fill in the array from [0] to [19]
				{	
					cout << setw(5) << i 
						 << setw(12) << a * (sine_values[i]) + b  		// y = a sin(x) + b
						 << endl;
				}
		
				cout << endl;											// to add a new line after the array, to make it easy to read
				
		break;
		
		case 4:
				cout << " ******  Quitting the program ******** " << endl;		// Quits the program and takes you out of the loop
		
		break;
		
		default:	
			cout << "invalid entry please try again" << endl << endl;		// if the user enter numbers other than 1,2,3,4, the loop will continue
																			// and will ask the user to input a valid input again
			
		}
		
	}while (choice != 4);
	
	
	

	
	return 0;
}	
	


// fills the array with the sine values of 0-19
void fill_array(double array[])
{

	for (int i(0); i < SIZE; i++)		// array [0] = sine of [0], then array[1] = sine [1], ...... and so on
		{
				array[i] = sin(i);
			
		}
}


void x_y_formatting()
{
	cout << endl
		 << setw(5) << " x" << "\t        y" << endl
		 << setw(5) << "--" << "\t   ------" << endl;
	
	
}
 
