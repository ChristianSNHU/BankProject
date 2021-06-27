#include "Banking.h"
#include<string>
#include<iostream>
#include<iomanip>
#include<stdexcept>

using namespace std;
/*
Collects and stores the user inputs for variables such as the years running and deposit amount.
This method itself does not have any parameters
nothing will be explicitly returned, though the inputs will change the global variables they are associated with
*/
void Banking::UserInput()
{
	//Try Catch exists to vet user input of anything that might cause an error
	try {
		cout << "Enter years of compounding\n";
		cin >> m_years;
		cout << endl;
		if (!cin || m_years < 1) {
			throw runtime_error("Invalid Input");
		}

		cout << "Enter initial deposit\n";
		cin >> m_depositAmount;
		cout << endl;
		if (!cin || m_depositAmount < 0) {
			throw runtime_error("Invalid Input");
		}

		cout << "Enter monthly deposit\n";
		cin >> m_openingAmount;
		cout << endl;
		if (!cin || m_openingAmount < 0) {
			throw runtime_error("Invalid Input");
		}

		cout << "Enter Interest\n";
		cin >> m_interestRate;
		m_interestRate /= 100;
		if (!cin || m_interestRate < 0) {
			throw runtime_error("Invalid Input");
		}
	}
	catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
			cout << "Can not calculate account" << endl;
	}
}
/*
Calculates and prints out the total account worth and yearly interest accumulation
t_interest is the interest rate of the account
t_years is the time that the program will run and determines how many iterations the method will operate
t_initial is the initial account balance. this is set once at the start, all future modifications to the balance are from interest.
Nothing is explicitly returned, but when called the function will print out a yearly earning chart for each year
*/
void Banking::NoDeposit(double t_interest, double t_years, double t_initial)
{
	double openingAmount; //the account balance after applying interest
	double closingAmount; //account balance before applying that months interest.
	double interest;	  //calculates just the interest earned this month
	double totInterest;	  //accumulates the total interest earned for the year, set to zero every 12 months

	openingAmount = t_initial;
	totInterest = 0;

	cout << "End of year earnings \t Interest earned for that year" << endl;

	for (int i = 1; i <= t_years * 12; i++)
	{
		openingAmount = (openingAmount);
		closingAmount = openingAmount;
		openingAmount = openingAmount + (openingAmount * ((t_interest) / 12.0));

		interest = openingAmount - closingAmount;
		totInterest += interest;

		//print out the account sheet only at the end of the year, if statement checks if i, the current month, is divisible wholely by 12, to print out the end of year statement
		if (i % 12 == 0)
		{
			cout << fixed << setprecision(2) << "\t" <<openingAmount << "\t\t\t" << totInterest << endl;
			totInterest = 0;	// reset the total interest saved at the end of the year
		}
	}
}
/*
Calculates and prints out the total account worth and yearly interest accumulation, along with a monthly deposit accumulation
t_interest is the interest rate of the account
t_years is the time that the program will run and determines how many iterations the method will operate
t_initial is the initial account balance
t_monthlyDeposit is the monthly addition of funds added to the account
Much like the previous functions nothing is returned, though calling will result in the printing of a chart with a yearly ballance and accumulation
*/
void Banking::Deposit(double t_interest, double t_years, double t_initial, double t_monthlyDeposit)
{

	// this method is near identical to the previouse, with the only difference being the adding of monthly deposits to openingAmount each month

	double openingAmount;
	double closingAmount;
	double interest;
	double totInterest;

	openingAmount = t_initial;
	totInterest = 0;

	cout << "End of year earnings \t Interest earned for that year" << endl;

	for (int i = 1; i <= m_years * 12; i++)
	{
		openingAmount = (openingAmount + t_monthlyDeposit);
		closingAmount = openingAmount;
		openingAmount = openingAmount + (openingAmount * ((t_interest)/12.0));

		interest = openingAmount - closingAmount;
		totInterest += interest;

		if (i % 12 == 0)
		{
			cout << fixed << setprecision(2) << "\t" << openingAmount << "\t\t\t" << totInterest << endl;
			totInterest = 0;	// reset the total interest saved at the end of the year
		}
	}
}
/*
Exists to allow main to call both Deposit and NoDeposit in a single call, as well as formats them to be easier to read
No parameters are used in this method itself, as it justs exists to call other methods and insert variables into them from global variables
Nothing is returned, only methods are being called
*/
void Banking::Output()
{
	cout << "\n----------------------------------------\n\n";
	cout << "\tTotal interest earned without monthly deposits\n" << endl;
	NoDeposit(m_interestRate, m_years, m_depositAmount);
	cout << "\n----------------------------------------\n\n";
	cout << "\tTotal Interest earned with monthly deposits\n" << endl;
	Deposit(m_interestRate, m_years, m_depositAmount, m_openingAmount);
}

