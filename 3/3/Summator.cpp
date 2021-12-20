#include <iostream>
#include "Summator.h"
#include <fstream>
using namespace std;

double Summator::calculate() const {
	double result = 0;
	for (int i = 0; i < operands_count; ++i) {
		result += operands[i];
	}
	return result;
}


void Summator::logToFile(const string& filename) const {
	ofstream fout;
	fout.open(filename, fstream::app);
	cout << "\n";
	fout << "Summator:" << endl;

	fout <<"[-" << operands_count << "- " << "operands ]" << endl;
	for (int i = 0; i < operands_count; ++i) {
		if (i < operands_count - 1) {
			if (operands[i] >= 0)
				fout << operands[i] << " plus ";
			else
				fout << "(" << operands[i] << ")" << " plus ";
		}
		else {
			if (operands[i] >= 0)
				fout << operands[i] << endl;
			else
				fout << "(" << operands[i] << ")";
		}
	}
	fout << "[-RESULT- " << calculate() << "]";
}

void Summator::logToScreen() const {
	cout << "\n";
	cout << "Summator:" << endl;

	cout << "[-" << operands_count << "- " << "operands ]" << endl;
	for (int i = 0; i < operands_count; ++i) {
		if (i < operands_count - 1) {
			if (operands[i] >= 0)
				cout << operands[i] << " plus ";
			else
				cout << "(" << operands[i] << ")" << " plus ";
		}
		else {
			if (operands[i] >= 0)
				cout << operands[i] << endl;
			else
				cout << "(" << operands[i] << ")";
		}
	}
	cout << "[-RESULT- " << calculate() << "]";
}