/*  File Name: program7.cpp
 *  Author: Hamza Tanveer
 *  Student ID: W836B668
 *  Assignment Number: 7
 *  Description: this program reads data from a file and processes it as listed in the requirements. 
 *				input file (rainfall.dat) contains the totatl rainfall fro each month of a year in millimeters for 20 different weather statioins
 * 				Each line of the file contains the data for one weather station, starting with the weather statuion number and followed by  the 12 rainfall measurements
 * 				one for each month. This is a text file and you can open it and view the data. You will see that all the values are integer
 *  Last Change: July 25, 2017
 */


#include <iostream>	//cin/cout
#include <fstream>	// reading data from a file
#include <cstdlib> // exit(1) for fail
#include <iomanip> //setw

using namespace std;

const int WEATHER_STATIONS = 20;
const int MONTHS = 12;
const double CONVERSION = 25.4; 	// 25.4mm = 1 inch



void display_years_more(double rainfall[] [12], int stations, double cutoff);
//precondition:  the formal parameter rainfall is a 2-dimensional array of
//				 a number station (second parameter) of 12 months each. 
//				 3rd parameter cutoff is avalue to which data in rainfall is compared to
//postcondition:: If the total rainfall of all 12 months for a weather station is GREATER than
//				   cutoff, then display the rainfall data (for all 12 months) for that station

void display_years_less(double rainfall[] [12], int stations, double cutoff);
//precondition:  the formal parameter rainfall is a 2-dimensional array of
//				 a number station (second parameter) of 12 months each. 
//				 3rd parameter cutoff is avalue to which data in rainfall is compared to
//postcondition:: If the total rainfall of all 12 months for a weather station is LESS than
//				   cutoff, then display the rainfall data (for all 12 months) for that station

void display_months_more(double rainfall[] [12], int stations, double cutoff);
//precondition:  the formal parameter rainfall is a 2-dimensional array of
//				 a number station (second parameter) of 12 months each. 
//				 3rd parameter cutoff is avalue to which data in rainfall is compared to
//postcondition:: Display the data for months whose rainfall is GREATER than cutof

void display_months_less(double rainfall[] [12], int stations, double cutoff);
//precondition:  the formal parameter rainfall is a 2-dimensional array of
//				 a number station (second parameter) of 12 months each. 
//				 3rd parameter cutoff is avalue to which data in rainfall is compared to
//postcondition:: Display the data for months whose rainfall is LESS than cutof


int main ()
{
	double rainfall[WEATHER_STATIONS][12];
	double millimeters;
	double cutoff;
	double discard_first_column;						// this variable discards the first value from each row
	int choice;
	
														//values will be displayed with 2 decimal places
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
														
	ifstream in_stream;
	in_stream.open("rainfall.dat");						//connecting input file stream to the file called "rainfall.dat"
														
	if (in_stream.fail())									// testing to see if the file opens or not
	{
		cout << " file couldn't open \n"; 				 // if file doesn't open, exit the program
		exit(1);
	}
	
	
	//reading the data from file rainfall.dat, converting values to inches and saving the rainfall measurements into this Array
	for (int i=0; i < WEATHER_STATIONS; i++)
	{
														// reads in the first value from each row and just discards it
		in_stream >> discard_first_column;
		
														// from the 2nd value onwards on each row, it starts to save those values in the array
		for (int x=0; x < MONTHS; x++)
		{	
														// take the value from rainfall.dat file and convert rain in millimeters to inches 
			in_stream >> millimeters;
			rainfall[i][x] = millimeters/CONVERSION;	// rain in inches = mm/25.4	
		}
	}	
	
														// closing the file to prevent any corruption of the file
	in_stream.close();	
	
	


	

	// do while loop, gives user the 5 options to choose from and then displays the menu again untill the user quits the program by choosing option 5. 
	do
	{	
		cout << "Rainfall data to display: \n"
			 << "\t 1. Weather stations with total rainfall for year MORE than a cutoff\n"
			 << "\t 2. Weather stations with total rainfall for year LESS than a cutoff\n"
			 << "\t 3. Rainfall for a month MORE than a cutoff\n"
			 << "\t 4. Rainfall for a month LESS than a cutoff\n"
			 << "\t 5. Quit\n"
			 << "Enter the number of your choice: ";
		cin  >> choice;
		
		switch(choice) 		// each case from 1 -4  asks the user to input cutoff value and plugs that argument into the formal parameters of the function call
		{
			case 1:
			{
				cout << "Enter the rainfall for which to find years with MORE rain (in inches): ";
				cin  >> cutoff;
				display_years_more(rainfall,  WEATHER_STATIONS,  cutoff);
				cout << endl;
			}	
			break;
			
			case 2:
			{
				cout << "Enter the rainfall for which to find years with LESS rain (in inches): ";
				cin  >> cutoff;
				display_years_less(rainfall,  WEATHER_STATIONS,  cutoff);
				cout << endl;
			}
			break;
			
			case 3:
			{
				cout << "Enter the rainfall for which to find months with MORE rain (in inches): ";
				cin  >> cutoff;
				display_months_more(rainfall,  WEATHER_STATIONS,  cutoff);
				cout << endl;
			}
			break;
			
			case 4:
			{
				cout << "Enter the rainfall for which to find months with MORE rain (in inches): ";
				cin  >> cutoff;
				display_months_less(rainfall,  WEATHER_STATIONS,  cutoff) ;
				cout << endl;
			}
			break;
			
			case 5:
				cout << "Thank you for using this program.\n";
			
			break;
			
			default: 
				cout << "Invalid choice selected. please choose again";  
				
		}
		
	}while (choice != 5); // exits the program with case 5
	
	
	return 0;	
}





void display_years_more(double rainfall[] [12], int stations, double cutoff)
{

	int i,x;
	for (i=0; i < WEATHER_STATIONS; i++)  	// outer forloop for the rows
	{
		double sum=0;						// sets the sum of the entire row to zero, so that next row year will have its rain added together
		
		for (x=0; x < MONTHS; x++)			// inner forloop for the column
		{	 
			sum =	rainfall[i][x] + sum;	// with each iteration add the sums up the rain from each weather station for 12 months		
		}
		
		if(sum > cutoff)					//when sum of rainfall for 12 months of a weather station is more then the cutoff amount given by the user
		{
			cout << "WS" << setw(3) << i+1 << ":";		// prints out the weather station number when the rain is MORE than the cutoff
			for (x=0; x < MONTHS; x++)
			{
			    cout << setw(6) <<rainfall[i] [x];		// prints out the the data for the 12 months of rain
			}
				cout << endl;
		}
	}	
}






void display_years_less(double rainfall[] [12], int stations, double cutoff)
{

	int i,x;
			
	for (i=0; i < WEATHER_STATIONS; i++)
	{
		double sum=0;
		
		for (x=0; x < MONTHS; x++)
		{		 
			sum =	rainfall[i][x] + sum;				// with each iteration add the sums up the rain from each weather station for 12 months	
		}
		
		if(sum < cutoff)								//when sum of rainfall for 12 months of a weather station is LESS then the cutoff amount given by the user
		{
			cout << "WS" << setw(3) << i+1 << ":";		// prints out the weather station number when the rain is LESS than the cutoff
			for (x=0; x < MONTHS; x++)
			{
			    cout << setw(6) <<rainfall[i] [x];		// prints out the the data for the 12 months of rain
			}
				cout << endl;
		}
	}
}




void display_months_more(double rainfall[] [12], int stations, double cutoff)
{

	int i,x;
	for (i=0; i < WEATHER_STATIONS; i++)
	{
		for (x=0; x < MONTHS; x++)
		{	
			if (rainfall[i][x] > cutoff)									// from the data, if in any month rain is more than the cutoff then print the following
			{
				cout << "Weather stations" << setw(3) << i+1 << ", "		// print weather station #
					 << "month" << setw(3) << x+1 << ":"					// print month #
					 << setw(6) <<rainfall[i][x] << " Inches" << endl;		//print the amount of rain inches for the month monre than the cutoff
			}
		}	
	}	
}




void display_months_less(double rainfall[] [12], int stations, double cutoff)
{

	int i,x;
	for (i=0; i < WEATHER_STATIONS; i++)
	{
		for (x=0; x < MONTHS; x++)
		{	
			if (rainfall[i][x] < cutoff)									// from the data, if in any month rain is more than the cutoff then print the following
			{
				cout << "Weather stations" << setw(3) << i+1 << ", "		// print weather station #
					 << "month" << setw(3) << x+1 << ":"					// print month #
					 << setw(6) <<rainfall[i][x] << " Inches" << endl;		//print the amount of rain inches for the month monre than the cutoff
			}		
		}
	}
}



