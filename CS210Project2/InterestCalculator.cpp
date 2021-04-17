/*
* Author: Sam Brasher
* Class: CS210-H4903
* Project: Project 2, Interest Calculator
* Date: 4/1/2021
*/

#include "InterestCalculator.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>

//Initialize all variables with -1 upon construction
InterestCalculator::InterestCalculator() {
	m_NumMonths = -1;
	m_OpeningAmount = -1;
	m_DepositAmount = -1;
	m_TotalAmount = -1;
	m_InterestRate = -1;
	m_EarnedInterest = -1;
	m_ClosingBalance = -1;
	m_YearEndInterest = -1;
}

//Starting function sets all variables to 0, then runs the input and calculation functions
void InterestCalculator::startCalculator() {
	m_NumMonths = 0;
	m_OpeningAmount = 0;
	m_DepositAmount = 0;
	m_TotalAmount = 0;
	m_InterestRate = 0;
	m_EarnedInterest = 0;
	m_ClosingBalance = 0;
	m_YearEndInterest = 0;
	printMenu();
	printMoney();
}

//PrintMenu() function is responsible for presenting the intial input menu.
void InterestCalculator::printMenu() {
	std::string userInput;
	double inputHolder;
	bool goodInput = false;
	
	/* 
	* This while loop with try/catch checks each input before
	* assigning it to the private member variable. If any improper
	* data is detected, the menu reprints and the user can input
	* data again.
	* 
	* Each input will throw an appropriate exception and inform
	* the user on the error.
	*/
	while (!goodInput) {
		try {
			std::cout << std::string(36, '*') << std::endl;
			std::cout << std::string(12, '*') << " Data Input " << std::string(12, '*') << std::endl;

			std::cout << "Initial Investment Amount: ";
			inputHolder = getInput();
			if (inputHolder <= 0) {
				throw 1;
			}
			else
				m_OpeningAmount = inputHolder;

			std::cout << "Monthly Deposit: ";
			inputHolder = getInput();
			if (inputHolder <= 0) {
				throw 1;
			}
			else
				m_DepositAmount = inputHolder;

			std::cout << "Annual Interest: ";
			inputHolder = getInput();
			if (inputHolder <= 0) {
				throw 2;
			}
			else
				m_InterestRate = inputHolder;

			std::cout << "Number of years: ";
			inputHolder = getInput();
			if (inputHolder <= 0)
				throw 3;
			else
				m_NumMonths = inputHolder * 12.0;	//To ensure we're calculating the number of months from entered years, we multiply by 12

			goodInput = true;
		}
		//This catch block catches the created excpetions and informs the user of the error
		catch (int e) {
			switch (e) {
			case 1:
				std::cout << "Please enter positive numbers in the format $XX.XX or XX.XX" << std::endl;
				system("pause");
				std::cout << fflush;
				system("CLS");
				break;
			case 2:
				std::cout << "Please enter positive whole numbers in the format %XX, XX% or XX" << std::endl;
				system("pause");
				std::cout << fflush;
				system("CLS");
				break;
			case 3:
				std::cout << "Please enter positive whole numbers in the format XX" << std::endl;
				system("pause");
				std::cout << fflush;
				system("CLS");
				break;
			}
		}
		//This catch block catches all other exceptions and allows continuation of the program.
		catch (...) {
			std::cout << "Exception occurred" << std::endl;
			system("pause");
			std::cout << fflush;
			system("CLS");
		}
	}
	system("pause");
	std::cout << fflush;
	system("CLS");
}

/*
PrintMoney() prints the money earned with and without monthly deposits.
The function displays one screen first - without monthly desposits. The data
is reset then with a button press, the second screen is display with monthly deposits.
*/
void InterestCalculator::printMoney() {
	double t_OpeningAmount = m_OpeningAmount;	

	std::cout << "\tBalance and Interest Without Additional Monthly Deposits\t" << std::endl;
	std::cout << std::string(75, '=') << std::endl;
	std::cout.width(YEAR_WIDTH);
	std::cout << std::right << "Year";
	std::cout.width(BALANCE_WIDTH);
	std::cout << std::right << "Year End Balance";
	std::cout.width(INTEREST_WIDTH);
	std::cout << std::right << "Year End Earned Interest" << std::endl;
	std::cout << std::string(75, '-') << std::endl;

	for (int i = 1; i <= m_NumMonths; i++) {
		m_TotalAmount = t_OpeningAmount;
		m_EarnedInterest = (m_TotalAmount) * (m_InterestRate / 100.0) / 12.0;
		m_ClosingBalance = m_TotalAmount + m_EarnedInterest;
		m_YearEndInterest += m_EarnedInterest;
		t_OpeningAmount = m_ClosingBalance;

		if (i % 12 == 0) {
			std::cout.imbue(std::locale("en_US.UTF-8"));
			std::cout.width(YEAR_WIDTH);
			std::cout << std::right << i / 12;
			std::cout.width(BALANCE_WIDTH);
			std::cout << std::showbase << std::right << std::put_money(m_ClosingBalance * 100);
			std::cout.width(INTEREST_WIDTH);
			std::cout << std::right << std::put_money(m_YearEndInterest * 100) << std::endl << std::endl;
			m_YearEndInterest = 0;
		}
	}
	system("pause");
	std::cout << fflush;
	system("CLS");

	std::cout << "\tBalance and Interest With Additional Monthly Deposits\t" << std::endl;
	std::cout << std::string(75, '=') << std::endl;
	std::cout.width(YEAR_WIDTH);
	std::cout << std::right << "Year";
	std::cout.width(BALANCE_WIDTH);
	std::cout << std::right << "Year End Balance";
	std::cout.width(INTEREST_WIDTH);
	std::cout << std::right << "Year End Earned Interest" << std::endl;
	std::cout << std::string(75, '-') << std::endl;

	m_TotalAmount = 0;
	m_EarnedInterest = 0;
	m_ClosingBalance = 0;
	m_EarnedInterest = 0;
	m_YearEndInterest = 0;
	t_OpeningAmount = m_OpeningAmount;

	for (int i = 1; i <= m_NumMonths; i++) {
		m_TotalAmount = t_OpeningAmount + m_DepositAmount;
		m_EarnedInterest = (m_TotalAmount) * (m_InterestRate / 100.0) / 12.0;
		m_ClosingBalance = m_TotalAmount + m_EarnedInterest;
		m_YearEndInterest += m_EarnedInterest;
		t_OpeningAmount = m_ClosingBalance;

		if (i % 12 == 0) {
			std::cout.imbue(std::locale("en_US.UTF-8"));
			std::cout << std::fixed << std::setprecision(2);
			std::cout.width(11);
			std::cout << std::right << i / 12;
			std::cout.width(25);
			std::cout << std::showbase << std::right << std::put_money(m_ClosingBalance * 100);
			std::cout.width(35);
			std::cout << std::right << std::put_money(m_YearEndInterest * 100) << std::endl << std::endl;
			m_YearEndInterest = 0;
		}
	}

}


/*
GetInput() accepts a user input as a string, then strips away everything but the integer.
This effectively ignores $ and %, ensuring the user does not have to enter them in a 
particular fashion.
The function returns 0 if there is no number entered (such as typing "five" rather than "5") or
if there is a negative number. This zero is handled by the calling function, as this function will not
throw errors itself.
*/
double InterestCalculator::getInput() {
	std::string userInput;
	double userValue;
	size_t i = 0;

	std::getline(std::cin, userInput);

	for (; i < userInput.length(); i++) {
		if (userInput[i] == '-')
			return 0;
		if (isdigit(userInput[i]) || userInput[i] == '.')
			break;
	}

	userInput = userInput.substr(i, userInput.length());
	userValue = atoi(userInput.c_str());

	return userValue;

}