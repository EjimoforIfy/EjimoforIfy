#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// convert feet to inches
	int feet, inches = 0;
	cout << "Enter height in feet and inches seperated with space:" << endl;
	cin >> feet >> inches;
	cout << "Height in feet and inches is " << feet << "ft, " << inches << "in"<<endl;
	inches += feet * 12;

	// covert height in inches to meters

	float heightinmeters = (inches * 25.4) / 1000;

	// Rounds output to two decimal places
	
	cout << "Height in meters is " << fixed<<setprecision(2) << heightinmeters << "m";

}