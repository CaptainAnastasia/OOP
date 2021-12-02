#include <iostream>
#include <string>
#include "Fraction.h"



int main()
{
	Fraction a(1, 2);
	Fraction b(2, 3);
	Fraction c = a + b;
	Fraction d = a - b;
	Fraction e = a * b;
	Fraction f = a / b;
	a.printFraction();
	b.printFraction();
	c.printFraction();
	d.printFraction();
	e.printFraction();
	f.printFraction();
	std::cout << "\n";
	char test1[] = "0.25";
	double test2 = 0.25;
	Fraction::printAsFraction(test1);
	Fraction::printAsFraction(test2);
	std::cout << "Total fractions: " << a.getTotalFractions() << "\n";
}