#pragma once
#include "ExpressionEvaluator.h"
#include <string>

class Summator : public ExpressionEvaluator {
public:
	void logToScreen() const override;
	void logToFile(const string& filename) const override;
	double calculate() const override;
};