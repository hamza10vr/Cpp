// File Name: program5.cpp
// Author: Hamza Tanveer
// Student ID: w836b668
// Assignment Number: 5
// Description: This program includes two functions that calculate unit conversions between a distance expressed
//				in feet and inches and in meters.
// Last Change: July 6, 2017


#include <iostream>
using namespace std;

const double METER_TO_INCHES = 0.0254;

void significant_digits ();		// rounding the decimals to 3 decimal places


int show_choices(int& choice);
//preconditions: prints out a menu with 3 choices to choose from & promts user to select a choice





// overloading function "get_input"
double get_input(double& meters);
//preconditons: formal parameter meters is a call by reference parameter
//				promts the user to input number of meters
//postconditionsreturns the double value

double get_input(int& feet, double& inches);
//preconditons: formal parameter feet and inches is a call by reference parameter
//				promts the user to input number of feet and inches





double unit_conversion_calculations(int& choice, double& meters, double& inches, int& feet);
//Preconditions: takes the call by reference formal parameters from previous funcions
//postconditions: performs the calculations based on the choise user selected and output the final results




void meters_to_feet_and_inches(double meters, int& feet, double& inches);
//converts meters to feet and inches, and sets the references parameters
// feet and inches to the result

double feet_and_inches_to_meters(int feet, double inches);
//converts feet and inches to meters and returns the result




int main ()
{
	double meters;
	double inches;
	int feet;
	int choice;

	significant_digits ();

	do
	{
		show_choices(choice);
	    unit_conversion_calculations(choice, meters, inches, feet);

	}while (choice !=3);


	return 0;
}

// rounds decimals to 3 decimals place
void significant_digits ()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

}


//prints out choice and promts user to choose one
int show_choices(int& choice)
{
		cout << "Available choices: \n"
			 << "\t 1. Convert meters to feet and inches \n"
			 << "\t 2. Convert feet and inches to meters \n"
			 << "\t 3. Quit \n"
			 << "Enter the number of your choices: ";
		cin  >> choice;
	return 0;
}



// prompts user to input number of meters
double get_input(double& meters)
{
		cout << endl << "Enter number of meters: ";
				cin  >> meters;

		return meters;
}


//prompts user to input feet and inches
double get_input(int& feet, double& inches)
{
	cout << endl <<  "Enter number of feet: ";
				cin  >> feet;
				cout <<  "Enter number of inches: ";
				cin  >> inches;
	return 0;
}



// performs conversion calculations based on the choise user selected. based on which conversion does the user want
double unit_conversion_calculations(int& choice, double& meters, double& inches, int& feet)
{

		switch(choice)
		{
			case 1:
				get_input(meters);		// calling function get_input

					if (meters <0)  // meters cant be negative, if negative then give an error otherwise perform calculation and give output
					{
						cout << "This program doesn't convert negative distances.\n" << endl;

					}
					else
					{

						meters_to_feet_and_inches( meters, feet, inches);
						cout << meters << " meters = "
							 << feet << " feet and "
							 << inches << " inches \n"
							 << endl;
					}
				break;

			case 2:

				get_input(feet,inches);  // calling function get_input

				if ((inches <0) || (feet <0) || (inches >12))  	// if inches and feet are negative numbers then give error otherwise perform calculations and give output
					{
						cout << "To convert a distance, neither feet nor inches can be negative and inches must be less than 12\n" << endl;

					}
					else
					{

						meters = feet_and_inches_to_meters(feet, inches);
						cout << feet << " feet and "
							 << inches << " inches = "
							 << meters << " meters \n"
							 << endl;
					}
				break;

			case 3:
				cout << "\t ******** quitting the program ********\n";
				break;

			default:
				cout << " invalid choice \n";
		}

	return 0;
}



// Converts meters to feet and inches, and sets the references parameters
// feet and inches to the result
void meters_to_feet_and_inches(double meters, int& feet, double& inches)
{
	// calculation for converting meters  to feet and inches
	feet = ((meters/METER_TO_INCHES)/12);
	inches = (((meters/METER_TO_INCHES)/(12)) - (feet))*12;

	return;
}



// converts feet an inches to meters and return the result double feet_and _inches_to_meters(int feet, double inches)
double feet_and_inches_to_meters(int feet, double inches)
{
	int inches2;
	double meters;

	// calculations for converting feet and inches to meters.
	inches2 = (feet * 12);
	meters = (inches2 + inches)*METER_TO_INCHES;

	return meters;
}
