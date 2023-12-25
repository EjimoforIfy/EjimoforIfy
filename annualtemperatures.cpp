#include<iostream>
using namespace std;

int main()
{
	int Newyork = 85,
		Denver = 88,
		Pheonix = 106;

	float PctIncrease = 0.15;

	cout << "NY average is " << Newyork << endl;
	cout << "Denver average is " << Denver << endl;
	cout << "Pheonix average is " << Pheonix << endl;
	cout << "If the averages temp rose by 15%" << endl;

	cout << "NY average would be " << (Newyork * PctIncrease) + Newyork << endl;
	cout << "Denver average would be " << (Denver * PctIncrease) + Denver << endl;
	cout << "Pheonix average would be " << (Pheonix * PctIncrease) + Pheonix << endl;


	
	return 0;
