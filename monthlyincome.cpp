#include <iostream>
using namespace std;

int main()
{
	int Basicpay = 5000;
	float BonusAmount = 0.55 * Basicpay;
	float Medicalallowance = 0.125 * Basicpay;

	// To get the overall total monthly income

	float TotalMonthlyPay = Basicpay + BonusAmount + Medicalallowance;
	cout<< "Basic Pay is $" << Basicpay << endl;
	cout<< "Bonus is $" << BonusAmount << endl;
	cout<< "Medical Allowance is $" << Medicalallowance << endl;
	cout << "Total is $" << TotalMonthlyPay << endl;
}
