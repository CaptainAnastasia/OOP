#pragma once
#include "ILoggable.h"
#include "IShuffle.h"
#include <string>
using namespace std;

class ExpressionEvaluator :public ILoggable {
public:
	ExpressionEvaluator();
	ExpressionEvaluator(size_t n);
	virtual ~ExpressionEvaluator();
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	void setOperand(size_t pos, double value);
	void setOperands(double ops[], size_t n);
	//void shuffle() const override = 0;
	//void shuffle(size_t i, size_t j) const override = 0;
	virtual double calculate() const = 0;
protected:
	double* operands;
	int operands_count = 0;
};