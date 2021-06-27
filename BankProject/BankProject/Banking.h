#pragma once

//This is the header class for the banking object. It is used to define all functions and global varaibles to be used in each instance of the object.

class Banking
{
public:

	void UserInput();
	void NoDeposit(double t_interest, double t_years, double t_initial);
	void Deposit(double t_interest, double t_years, double t_initial, double t_monthlyDeposit);
	void Output();	

private:

	int m_years;			//years that the program will calculate interest for, displayed for each month of however many years
	double m_openingAmount; //amount deposited monthly
	double m_depositAmount; //initial amount in account
	double m_interestRate;	//rate of interest over the accounts forecast
}
;
