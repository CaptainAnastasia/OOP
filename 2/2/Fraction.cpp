#include <iostream>
#pragma once
#include <cmath>
#include "Fraction.h"
using namespace std;
static int s_gcd = 1;

int Fraction::s_counter() {
	static int cntr = 0;
	++cntr;
	return cntr;
}

void Fraction::reduce() {
	int k = 2;

	for (size_t i = 0; i < 500; i++) {
		if ((x % k == 0) and (y % k == 0)) {
			x = x / k;
			y = y / k;
			//cout << " Reduced by " << k <<" fraction: " << x << " / " << y << "\n";
			s_gcd *= k;
		}
		else {
			k++;
		}
	}
}

int Fraction::gcd() { 
	return s_gcd;
}
int Fraction::gcdNull() { 
	s_gcd = 1;
	return s_gcd;
}


double Fraction::operator+() {
	Fraction fr0;
	fr0.x = x * y1 + x1 * y;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator-() {
	Fraction fr0;
	fr0.x = x * y1 - x1 * y;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator*() {
	Fraction fr0;
	fr0.x = x * x1;
	fr0.y = y * y1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}
double Fraction::operator/(double div) {
	Fraction fr0;
	fr0.x = x * y1;
	fr0.y = y * x1;
	fr0.reduce();
	cout << fr0.x << " / " << fr0.y << endl;
	double val = fr0.x / fr0.y;
	return (double)(val);
}


void Fraction::printAsFraction(double decimal_fraction) {
	int numerator; 
	int denominator = 1; 

	for (size_t i = 0; i < 7; i++) {
		decimal_fraction *= 10;
		denominator *= 10;
	}
	numerator = (int)decimal_fraction;
	//cout << numerator << " / " << denominator << "\n";

	Fraction fr;
	fr.x = numerator;
	fr.y = denominator;
	fr.reduce();
	cout << "\n\n\tOrdinary fraction : " << fr.x << " / " << fr.y << "\n\n";
}

void Fraction::printAsFraction(char* decimal_fraction) {
	double decFract = atof(decimal_fraction);

	int numerator; 
	int denominator = 1; 

	for (size_t i = 0; i < 7; i++) {
		decFract *= 10;
		denominator *= 10;
	}
	numerator = (int)decFract;
	//cout << numerator << " / " << denominator << "\n";

	Fraction fr;
	fr.x = numerator;
	fr.y = denominator;
	fr.reduce();
	cout << "\n\n\tOrdinary fraction : " << fr.x << " / " << fr.y << "\n\n";
}