/*
* Author: Sam Brasher
* Class: CS210-H4903
* Project: Project 2, Interest Calculator
* Date: 4/1/2021
*/

#include "InterestCalculator.h"
#include <iostream>

/*
The main function instantiates an object with a unique pointer, 
and calls the startCalculator member function
*/

int main() {

	auto interestCalculator = std::make_unique<InterestCalculator>();
	interestCalculator->startCalculator();

	return 0;
}