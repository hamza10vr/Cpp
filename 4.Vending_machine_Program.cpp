// File Name: program4.cpp
// Author: Hamza Tanveer
// Student ID: W836B668
// Assignment Number: 4
// Description: program which will model accepting payment and giving change for a snack vending maching
// machine will contain potato chips, snickers bar, pop tart, cookies, brownies and nuts
// shown with label used to select the item and its price
// Last Change: July 3,2017




#include <iostream>  // cout, cin, endl
#include <iomanip>	//setw 
#include <cctype>   // toupper

int menu(void);
//precondition: displays the list of snack items and prompt the user for their choice
//
//postcondition:if the user makes a valid selection, the function returns the total_price of that selction
//				otherwise the user is re-prompted for choice until a valid choice from the menu is obtained.

int accept_money(int price);
//precoindtion: displays user a choice of coins to insert
//				
// postcondition: adds up the total amount inserted by the user, ask the user again for more coins until the total amount is equal
//				  to or greater than the price. once this loop is complete, the function returns the total amount of
//				  money (total_paid) inserted by the user

int compute_change(int total_paid, int total_price);
//precondition: total_paid is the total amount of coins inserted, total_price is the price of item selected
//postconditon: return the change owed to the user

using namespace std;




int main ()

{
	int total_price, total_paid;
	char ans;
	
	//loop created to allow the user to purchase another item after completing the previous transaction
	do
	{
	
		total_price = menu(); 		
		total_paid = accept_money(total_price);
		compute_change (total_paid, total_price);
		
		
		cout << "Would you care to make another purchase? (Y/N): ";
		cin  >> ans;
		ans = toupper(ans);
		
	} while (ans == 'Y');
	
	cout << endl << "Thank you and enjoy your purchase! \n" <<endl;
	
	
	return 0;
}



// uses ioustream, 
int menu(void)
{
	
	
	int price;
	char selection;
	
	
	cout << "Welcome to the snack vending maching " << endl
		 << "Available snacks to select from: " << endl
		 << "\t P  -  Potato Chips	$ 1.25 " << endl
		 << "\t S  -  Snickers Bar	$ 1.35 " << endl
		 << "\t T  -  Pop Tart		$ 0.95 " << endl
		 << "\t C  -  Cookies		$ 1.50 " << endl
		 << "\t B  -  Brownies		$ 1.75 " << endl
		 << "\t N  -  Nuts		$ 1.40 " << endl; 
		 
		 
	//	if the user enters an invalid slection, loop is created which will re-prompt the user for another choice
	// until a valid choice from the menu is selected
	do
	 {	
		cout << "Please enter the letter labeling your snack selection: ";
		cin  >> selection;
		selection = toupper(selection); // uses <cctype> converts lowercase to uppercase
		cout << endl;
	
		 
		 switch(selection)
		 {
			 case 'P': 
				price = 125;
				break;
			  case 'S':
				price = 135;
				break;
			  case 'T':
				price = 95;
				break;
			  case 'C': 
				price = 150;
				break;
			  case 'B': 
				price = 175;
				break;
			  case 'N': 
				price = 140;
				break;
				
			  default:
					cout << "Invalid selection! \n";		  
		 } 
		 // with && 
					// l - t t t t t t  - true loop again
					// s - t f t t t t  - false no loop using short circut method
		// with ||
					// l - f f f f f f  - loop again
					// s - t f t t t t  - true
	}while ((selection != 'P') && (selection != 'S') && (selection != 'T') 
			&& (selection != 'C') && (selection != 'B') && (selection != 'N'));


	return price;
}


int accept_money(int price)
{
	char payment_method;
	int  paid=0;
	
	cout << "Money accepted by the machine: \n"
		 <<  "	N  -  Nickel" << endl
		 <<  "	Q  -  Quarter" << endl
		 <<  "	D  -  Dollar" << endl << endl;

	// loop  created to prevent user from entering an invalid coin. if invalid payment is entered it will re-prompt the use 
	// to re-enter the payment
	do
	{
		
		cout << "Your selected snack item costs: "  << price <<" CENTS" << endl
			 << "Your total inserted: " <<  setw(14) << paid  <<" CENTS" << endl
			 << "Insert amount (enter letter of choice): " ;
		cin  >> payment_method;
		payment_method = toupper(payment_method);// uses <cctype> converts lowercase to uppercase
		cout << endl;	
		
		
		switch (payment_method)
		{
			case 'N': paid += 5;
				break;
				
			case 'Q':  paid += 25;
				break;
				
			case 'D':  paid += 100;
				break;
			
			default:
				cout << payment_method <<" is not recoognized as a coin \n" << endl;
		}

		
	} while (paid < price);
			
	
	
	return paid;
	
}

int compute_change(int total_paid, int total_price)
{
		//returns the change owed to the user,  found by subtracting total_price from total_paid
		cout <<"Your total inserted: " << total_paid << " CENTS" << endl
			 << "Dispensing change : " <<  setw(4) << (total_paid - total_price) << " CENTS" << endl << endl;
			 
	return 0;
	
}

