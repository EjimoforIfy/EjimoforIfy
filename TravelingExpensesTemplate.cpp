// This program creates a business travel expense report, which it
// writes to a file.

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// Function prototypes	
string getTripDates();
int getNightsAway();
double getAirFare();
double getCarRental();
double getMilagePmt();
double getParking();
double getTaxiFees();
double getRegistrationFee();
double getHotelCost(int);
double getMealCosts();

const double
MILAGE_ALLOWANCE = .58,      // Per mile driven
MAX_HOTEL_RATE = 120.00;     // Per night max

int main()
{
	ofstream report;          // Create ofstream object that will point
	// to the output file for the expense report
	string name,
		tripDates;

	int nights;               // Number of nights away from home 

	double /*Expenses*/
		air = 0.0,
		carRental = 0.0,
		milage = 0.0,
		parking = 0.0,
		taxis = 0.0,
		registration = 0.0,
		hotelSpent = 0.0,
		hotelAllowed = 0.0,
		meals = 0.0,
		totalSpent = 0.0,
		totalAllowed = 0.0;

	// Open the report file
	report.open("Expense.rpt");

	// Write screen and report headings
	cout << "\tEmployee Expense report\n\n";
	cout << "Employee name: ";       // Not required by program specs
	getline(cin, name);

	report << fixed << showpoint << setprecision(2);
	report << "\t Employee Expense Report for " << name << "\n";
	report << "\t   Trip Dates: " << getTripDates() << "\n\n";
	report << "                  Spent      Allowed \n"
		<< "                 ------      ------- \n";

	// Call functions to calculate specific expenses
	nights = getNightsAway();
	air = getAirFare();
	carRental = getCarRental();
	milage = getMilagePmt();
	parking = getParking();
	taxis = getTaxiFees();
	registration = getRegistrationFee();
	hotelSpent = getHotelCost(nights);
	hotelAllowed = nights * MAX_HOTEL_RATE;
	meals = getMealCosts();

	totalAllowed = totalSpent = air + carRental + milage + parking
		+ taxis + registration + hotelSpent + meals;

	if (hotelSpent > hotelAllowed)
		totalAllowed = totalAllowed - hotelSpent + hotelAllowed;



	// Write the report to the file
	report << "Airfare        " << setw(8) << air << "     "
		<< setw(8) << air << endl;
	report << "Car rental     " << setw(8) << carRental << "     "
		<< setw(8) << carRental << endl;
	report << "Milage         " << setw(8) << milage << "     "
		<< setw(8) << milage << endl;
	report << "Parking        " << setw(8) << parking << "     "
		<< setw(8) << parking << endl;
	report << "Taxis          " << setw(8) << taxis << "     "
		<< setw(8) << taxis << endl;
	report << "Registration   " << setw(8) << registration << "     "
		<< setw(8) << registration << endl;
	report << "Hotel          " << setw(8) << hotelSpent << "     "
		<< setw(8) << hotelAllowed << endl;
	report << "Meals          " << setw(8) << meals << "     "
		<< setw(8) << meals << endl;
	report << "                -------      ------- \n";
	report << "TOTALS         $" << setw(7) << totalSpent << "     $"
		<< setw(7) << totalAllowed << endl;

	report.close();

	// Display a message on the screen
	cout << "\nThe expense report has been written to the Expense.rpt file.\n";
	return 0;

}// end of main function

/***********************************************
 *                 getTripDates                *
 * This function inputs and return trip dates. *
 ***********************************************/
string getTripDates()
{
	string startDate, endDate;

	cout << "Enter the departure date (mm/dd/yy): ";
	cin >> startDate;

	cout << "Enter the return date (mm/dd/yy): ";
	cin >> endDate;

	return startDate + " - " + endDate;

}// end of function getTripDates

/*****************************************
 *             getNightsAway             *
 * This function inputs and returns the  *
 * number of nights away on the trip.    *
 *****************************************/
int getNightsAway()
{
	int nights;

	cout << "How many nights were you away from home on the trip? ";
	cin >> nights;
	return nights;

}// end of function getNightsAway

/***************************************************************
 *                        getAirFare                           *
 * This function inputs, validates, and returns air fare.      *
 ***************************************************************/
double getAirFare()
{
	double fare;

	cout << "Enter the amount of airfare: ";
	cin >> fare;
	while (fare < 0)
	{
		cout << "This expense must be 0 or greater. Please re-enter: ";
		cin >> fare;
	}
	return fare;

}// end of function getAirFare

/*************************************************
 *                    getCarRental               *
 * This function inputs, validates, and returns  *
 * car rental expenses.                          *
 *************************************************/
double getCarRental()
{
	double rental;

	cout << "Enter the amount spent for car rental: ";
	cin >> rental;
	while (rental < 0)
	{
		cout << "This expense must be 0 or greater. Please re-enter: ";
		cin >> rental;
	}
	return rental;

}// end of function getCarRental

/****************************************
 *             getMilagePmt             *
 * This function computes and returns   *
 * milage reimbursement                 *
 ****************************************/
double getMilagePmt()
{
	int miles;

	cout << "Number of miles driven by private vehicle: ";
	cin >> miles;
	while (miles < 0)
	{
		cout << "Miles driven must be 0 or greater.  Please re-enter: ";
		cin >> miles;
	}
	return miles * MILAGE_ALLOWANCE;

}// end of function getMilagePmt

/***************************************************************
 *                     getParking                              *
 * This function inputs, validates, and returns parking fees   *
 ***************************************************************/
double getParking()
{
	double parking;
	cout << "Enter the amount of any parking fees: ";
	cin >> parking;
	while (parking < 0)
	{
		cout << "Parking fees must be 0 or greater. Please re-enter: ";
		cin >> parking;
	}
	return parking;

}// end of function getParking

/************************************************************
 *                        getTaxiFees                       *
 * This function inputs, validates, and returns taxi fees.  *
 ************************************************************/
double getTaxiFees()
{
	double taxi;

	cout << "Enter the amount of any taxi fees: ";
	cin >> taxi;
	while (taxi < 0)
	{
		cout << "Taxi fees must be 0 or greater. Please re-enter: ";
		cin >> taxi;
	}
	return taxi;

}// end of function getTaxiFees

/*************************************************
 *               getRegistrationFee              *
 * This function inputs, validates, and returns  *
 * any conference registration fee.              *
 *************************************************/
double getRegistrationFee()
{
	double registration;

	cout << "Enter the amount of any conference registration: ";
	cin >> registration;
	while (registration < 0)
	{
		cout << "This expense must be 0 or greater. Please re-enter: ";
		cin >> registration;
	}
	return registration;

}// end of function  getRegistrationFee

/***********************************************************
 *                     getHotelCost                        *
 * This function inputs, validates, and stores both        *
 * spent and allowed hotel costs in reference parameters.  *
 * It assumes all nights were at the same rate.            *
 ***********************************************************/
double getHotelCost(int nights)
{
	double rate, hotel;

	cout << "Enter the nightly hotel rate (0 if none used): ";
	cin >> rate;
	while (rate < 0)
	{
		cout << "Room rate must be 0 or greater.  Please re-enter: ";
		cin >> rate;
	}
	hotel = nights * rate;

	return hotel;
}// end of function getHotelCost

/****************************************************
 *                    getMealCosts                  *
 * This function calculates total spent for meals   *
 ****************************************************/
double getMealCosts()
{
	double meals;

	cout << "Enter total spent for meals: ";
	cin >> meals;
	while (meals < 0)
	{
		cout << "Meals total must be 0 or greater.  Please re-enter: ";
		cin >> meals;
	}
	return meals;
}// end of function getMealCosts

/* SAMPLE RUN I/O

	Employee Expense report

Employee name: Tom Sawyer
Enter the departure date (mm/dd/yy): 11/2/19
Enter the return date (mm/dd/yy): 11/4/19
How many nights were you away from home on the trip? 2
Enter the amount of airfare: 429
Enter the amount spent for car rental: 130
Number of miles driven by private vehicle: 0
Enter the amount of any parking fees: 22
Enter the amount of any taxi fees: 0
Enter the amount of any conference registration: 200
Enter the nightly hotel rate (0 if none used): 130
Enter total spent for meals: 144

The expense report has been written to the Expense.rpt file.

REPORT WRITTEN TO THE FILE WHEN THIS PROGRAM WAS RUN USING THE INPUTS SHOWN ABOVE

	 Employee Expense Report for Tom Sawyer
	   Trip Dates: 11/2/19 - 11/4/19

				  Spent      Allowed
				 ------      -------
Airfare          429.00       429.00
Car rental       130.00       130.00
Milage             0.00         0.00
Parking           22.00        22.00
Taxis              0.00         0.00
Registration     200.00       200.00
Hotel            260.00       240.00
Meals            144.00       144.00
				-------      -------
TOTALS         $1185.00     $1165.00
*/