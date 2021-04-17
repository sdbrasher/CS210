/*
* Author: Sam Brasher
* Class: CS210-H4903
* Project: Project 2, Interest Calculator
* Date: 4/1/2021
*/

#ifndef INTERESTCALCULATOR_H_
#define INTERESTCALCULATOR_H_
class InterestCalculator {

public:

	InterestCalculator();
	void startCalculator();
	const int YEAR_WIDTH = 11;
	const int BALANCE_WIDTH = 25;
	const int INTEREST_WIDTH = 35;

private:

	void printMenu();
	void printMoney();
	double getInput();
	double m_NumMonths;
	double m_OpeningAmount;
	double m_DepositAmount;
	double m_TotalAmount;
	double m_InterestRate;
	double m_EarnedInterest;
	double m_ClosingBalance;
	double m_YearEndInterest;
};

#endif