// Chapter5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Function must be declared before being used.
double avg(double x, double y);

int main()
{
	double a = 0.0;
	double b = 0.0;

	cout << "Enter first number and press ENTER: ";
	cin  >> a;
	cout << "Enter second number and press ENTER: ";
	cin >> b;

	// Call the function avg
	cout << "Average is: " << avg(a, b) << "." << endl << endl;

	system("PAUSE");

    return 0;
}

// Average-number function def.
//
double avg(double x, double y) {
	return (x + y) / 2;
}

