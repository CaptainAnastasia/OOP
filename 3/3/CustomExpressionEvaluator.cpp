#include "CustomExpressionEvaluator.h"
#include <fstream>
#include <iostream>

double CustomExpressionEvaluator::calculate() const {
	double result = 0;
	for (int i = 0; i < operands_count; ++i) {
		if (i == 0) {
			result = operands[0] / operands[1];
		}
		else if (i == 1) {
			skipws;
		}
		else
		{
			result += operands[i];
		}
	}
	return result;
}

void CustomExpressionEvaluator::logToScreen() const {
	cout << "[-" << operands_count << "- " << "operands ]" << endl;
	for (int i = 0; i < operands_count; ++i) {
		if (i == 0) {
			if (operands[i] >= 0)
				cout << operands[i] << " share ";
			else
				cout << "(" << operands[i] << ")" << " share ";
		}
		else if (i < operands_count - 1) {
			if (operands[i] >= 0)
				cout <<  operands[i] << " plus ";
			else
				cout <<"(" << operands[i] << ")" << " plus ";
		}
		else {
			if (operands[i] >= 0)
				cout <<  operands[i] << endl;
			else
				cout <<  "(" << operands[i] << ")" << endl;
		}
	}
	cout << "[-RESULT- " << calculate() << "]";
	cout << "\n";
}

void CustomExpressionEvaluator::logToFile(const string& filename) const {
	ofstream fout;
	fout.open(filename, fstream::app);
	fout << "CustomExpressionEvaluator:" << endl;
	fout << "[-" << operands_count << "- " << "operands ]" << endl;
	for (int i = 0; i < operands_count; ++i) {
		if (i == 0) {
			if (operands[i] >= 0)
				fout << operands[i] << " share ";
			else
				fout << "(" << operands[i] << ")" << "share ";
		}
		else if (i < operands_count - 1) {
			if (operands[i] >= 0)
				fout <<  operands[i] << " plus ";
			else
				fout <<  "(" << operands[i] << ")" << " plus ";
		}
		else {
			if (operands[i] >= 0)
				fout <<  operands[i] << endl;
			else
				fout <<  "(" << operands[i] << ")" << endl;
		}
	}
	fout << "[-RESULT- " << calculate() << "]";
	fout << "\n";
	fout << endl;
}

void CustomExpressionEvaluator::shuffle() const {
	double temp;
	for (int i = 0; i < operands_count; ++i) {
		for (int j = i; j < operands_count; ++j) {
			if (operands[i] > operands[j]) {
				int temp = operands[i];
				operands[i] = operands[j];
				operands[j] = temp;
			}
		}
	}
}


void CustomExpressionEvaluator::shuffle(size_t i, size_t j) const {
	double temp;
	if (operands[j] >= 0) operands[j] = operands[j];
	if (operands[i] < 0) operands[i] = operands[i];

	temp = operands[j];
	operands[j] = operands[i];
	operands[i] = temp;
}