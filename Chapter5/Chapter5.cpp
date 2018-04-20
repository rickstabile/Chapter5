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
void get_divisors(int n);

int main()
{
	double a = 0.0;
	double b = 0.0;

	// Floating point calculation test ... or 
	// "Why you should never check floats or doubles for
	//  equivalence."
	cout << endl << "-------------" << "Floating point equivalence test.";
	cout << endl << endl;
	cout << "Testing ... " << endl;
	cout << "a = (100 + 1.0 / 3) - 100;" << endl;
	cout << "b = 1.0 / 3;" << endl;

	a = (100 + 1.0 / 3) - 100;
	b = 1.0 / 3;
	cout << "Is a == b true?" << endl;

	if (a == b) {
		cout << "This is true ... " << endl;
	}
	else {
		cout << "This is false ... " << endl;
	}

	cout << endl << "---------------" << endl << endl;

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
			cout << "not prime." << endl << endl;
			cout << "Divisors for " << n << " are: " << endl;
			get_divisors(n);
			cout << endl << endl;
		}
		else {
			cout << "prime." << endl << endl;

			cout << "Divisors for " << n << " are: " << endl;
			get_divisors(n);
			cout << endl << endl;
		}

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
	bool returnValue = ( n > 1 );

	int upperBound = floor(sqrt(n)) + 1;

	for (int counter = 2; counter < upperBound; ++counter) {
		// cout << endl;
		// cout << "n:          " << n          << endl;
		// cout << "upperBound: " << upperBound << endl;
		// cout << "counter:    " << counter    << endl << endl;

		if ((counter == 2 || prime(counter)) &&
			 n % counter == 0) {
			returnValue = false;
			break;
		}
	}

	return returnValue;
}

void get_divisors(int n) {
	double sqrt_of_n = sqrt(n);
	int upperLimit = ceil(sqrt_of_n);

	if (upperLimit - sqrt_of_n < .00000001f) {
		upperLimit += 1;
	}

	for (int i = 2; i < upperLimit; ++i) {
		if (n % i == 0) {
			cout << i << ", ";
			get_divisors(n / i);
			return;
		}
	}

	cout << n;
}

