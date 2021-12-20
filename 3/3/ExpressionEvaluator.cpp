#include <fstream>
#include <iostream>
#include "ExpressionEvaluator.h"

ExpressionEvaluator::ExpressionEvaluator() {
	operands = new double[20];
	for (int i = 0; i < 20; ++i) {
		operands[i] = 0;
	}
}

ExpressionEvaluator::ExpressionEvaluator(size_t n) {
	operands = new double[n];
	for (int i = 0; i < n; ++i) {
		operands[i] = 0;
	}
}

void ExpressionEvaluator::setOperand(size_t pos, double value) {
	if (operands[pos] == 0) operands_count++;
	operands[pos] = value;

}
void ExpressionEvaluator::setOperands(double ops[], size_t n) {
	for (int i = 0; i < n; ++i) {
		operands[i] = ops[i];
	}
	operands_count = n;
}
ExpressionEvaluator:: ~ExpressionEvaluator() {
	delete[] operands;
	operands_count = 0;
}

void ExpressionEvaluator::logToScreen() const {
	cout << "no class to operate the expression";
}

void ExpressionEvaluator::logToFile(const std::string& filename) const {
	ofstream fout;
	fout.open(filename);
	fout << "no class to operate the expression";

}