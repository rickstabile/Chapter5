// Chapter5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;

// Functions must be declared before being used.
void print_results(double a, double b);
double avg(double x, double y);

bool prime(int n);
void get_divisors(int n);
int gcf(int a, int b);

int gcf_loop(int a, int b);
int rand_0toN1(int n);

int main()
{
	int numberOfDice = 0;
	int diceResult = 0;

	// Set seed for randomizing.
	srand(time(nullptr));
	cout << "--- ROLLING THE DICE ---\n";
	cout << "------------------------\n\n";
	cout << "Enter number of dice to roll: ";
	cin >> numberOfDice;

	cout << endl;
	for (int i = 0; i < numberOfDice; i++) {
		diceResult = rand_0toN1(6) + 1; // Get a number between 1 and 6 (inclusive)
		
		// Print.
		cout << "Result " << i + 1 << ": " << diceResult << ".\n";
	}

	cout << "\n------------------------\n\n";

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

	// Call the gcf() function.
	int gcf_value = gcf(a, b);
	int gcf_loop_value = gcf_loop(a, b);

	cout << "GCF for " << a << " and " << b << " is: ";
	cout << gcf_value << ".";

	cout << endl << endl << "----------------" << endl;

	cout << "Using loop function ... \n";
	cout << "GCF for " << a << " and " << b << " is: ";
	cout << gcf_loop_value << ".";

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

int gcf(int a, int b) {
	if (b == 0) {
		cout << "End of Recursion\n\n";
		cout << "----------------\n";
		return a;
	}
	else {
		cout << "Calling gcf(" << b << ", " << a % b << ")\n";
		return gcf(b, a % b);
	}
}

int gcf_loop(int a, int b) {
	int temp = 0;

	while (b != 0) {
		temp = a % b;
		a = b;
		b = temp;
	}

	return a;
}

// Random 0-to-N1 function.
// Generate a random integer from 0 to n-1, with each 
// integer an equal probability.
//
int rand_0toN1(int n) {
	return rand() % n;
}

