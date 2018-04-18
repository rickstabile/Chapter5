// Chapter5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

// Functions must be declared before being used.
void print_results(double a, double b);
double avg(double x, double y);

bool prime(int n);

int main()
{
	double a = 0.0;
	double b = 0.0;

	cout << "Enter first number and press ENTER: ";
	cin  >> a;
	cout << "Enter second number and press ENTER: ";
	cin >> b;

	// Call the function avg
	// cout << "Average is: " << avg(a, b) << "." << endl << endl;

	// Call the print_results() function.
	print_results(a, b);

	cout << endl << endl << "----------------" << endl;
	int n = 0;
	
	do {
		cout << "Prime number test ... Enter a number to test (0 to end): ";
		cin >> n;
		cout << endl << endl;

		if (n == 0) {
			cout << "BYE!!!" << endl << "------------" << endl << endl;
			break;
		}

		cout << "The number you entered, " << n << " is ";
		if (!prime(n)) {
			cout << "not ";
		}
		cout << "prime." << endl << endl;

	} while (true);

	system("PAUSE");

    return 0;
}

// print_results function def.
//
void print_results(double a, double b) {
	cout << "The average is: " << avg(a, b) << endl;
}

// Average-number function def.
//
double avg(double x, double y) {
	return (x + y) / 2;
}

bool prime(int n) {
	bool returnValue = true;

	int upperBound = ceil(sqrt(n));

	for (int counter = 2; counter < upperBound; ++counter) {
		if (n % counter == 0) {
			returnValue = false;
			break;
		}
	}

	return returnValue;
}

