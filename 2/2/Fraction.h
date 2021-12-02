#pragma once
#include <iostream>
#include <string>
class Fraction
{
private:
	int n_;
	int m_;
	static int fractionCounter;
public:
	Fraction();
	Fraction(int n, int m); // x = n/m
	void setM(int m);
	void setN(int n);
	int getM();
	int getN();
	int getTotalFractions();

	Fraction operator +(const Fraction& term);
	Fraction operator -(const Fraction& subtrahend);
	Fraction operator *(const Fraction& factor);
	Fraction operator /(const Fraction& divisor);

	void reduce(); // ñîêðàòèòü
	static int gcd(int n, int m); // íàèáîëüøèé îáùèé äåëèòåëü ïî àëãîðèòìó åâêëèäà
	static void printAsFraction(double decimal_fraction); // âûâîä åñëè èíïóò öèôðû
	static void printAsFraction(char* decimal_fraction); // âûâîä åñëè èíïóò òåêñò
	void printFraction();
};