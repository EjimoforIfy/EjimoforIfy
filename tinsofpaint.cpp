#include<iostream>
#include<cmath>
using namespace std;


int main()
{
	// Calculate Area of Fence //

	int Height = 6,
		Length = 100,
		sqftpergallon = 340,
		areaofFence,
		numCoats = 2;

	double coverageperTin = 340,
		numberoftins;

	areaofFence = Length * Height;
	numberoftins = areaofFence / coverageperTin;

	cout << " How many square feet is your fence  " << areaofFence << endl;
	cout << " Number of tins needed to paint the fence " << numberoftins << Length << " / " << Height << endl;
		
	return 0;
}
