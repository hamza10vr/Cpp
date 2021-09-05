// File Name: program3.cpp
// Author: Hamza Tanveer
// Student ID: W836B668
// Assignment Number: 3
// Description: given the loan, interest rate, and monthly payment, this program calculates the interest, applies the payment
// and calculate the the rermaining balance. Thne pfor each year, displays a table with each month'sinterest and principal payments
// and the laod balance after that month's Payment is made. At the end of the year displas the total interest and toral principal for that year
// Last Change: June 28,2017




#include <iostream>  // cout, cin, endl
#include <iomanip>	//setw

using namespace std;
int main (void)

{

	double annual_interest_rate;
	double monthly_interest_rate;
	double monthly_payment;
	double interest;
	double principal;
	double balance;




	// numbers with fractions displayed with 2 places after decimal points
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision (2);


	cout << "Enter amount of loan:  ";
	cin  >> balance;
	cout << "Enter interest rate:   "; 	// user will input the "annual" interest rate
	cin  >> annual_interest_rate;
	cout << "Enter monthly payment: ";
	cin  >>monthly_payment;

	// annual interest rate is converted to monthly interest rate
	monthly_interest_rate = (annual_interest_rate/100) /(12);


	for (int year =1; year <=3; year++)		//First loop to print out the variables for each year
	{
			// at the beginning of every year totals will be set to zero.
			double total_interest=0.0;
	        double total_principal=0.0;

			// setw(15) used to right-aligned the columns of month, interest, Principal, and balance.
			cout << endl <<"YEAR " << year <<endl
				 << setw(15) <<" Month " << setw(15) <<" Interest " <<  setw(15) <<" Principal " << setw(15) <<" Balance " <<endl
				 << setw(15) <<" ----- " << setw(15) <<" -------- " << setw(15) <<" --------- " << setw(15) <<" -------- " << endl;

			for (int month =1; month <=12; month++) 	// nested loop within the first loop for calculation for each year
			{
					// calculations for interest, balance, principal,total interest, and total principal
					interest = (balance )* (monthly_interest_rate);
					principal = (monthly_payment) - (interest);
					balance -= (principal);


					total_interest += interest;
					total_principal += principal;


					cout << setw(14) << month << setw(15) << interest << setw(15) << principal << setw(15) << balance<< endl;

			}

			cout << setw(29) << "------" << setw(15) << "------" << endl
				 << "Year totals: " << setw(16) << total_interest << setw(15) << total_principal << endl << endl;


	}


	return 0;
}
