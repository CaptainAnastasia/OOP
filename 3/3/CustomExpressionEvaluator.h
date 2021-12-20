#pragma once
#include "ExpressionEvaluator.h"
#include "IShuffle.h"
#include <iostream>

class CustomExpressionEvaluator : public ExpressionEvaluator, public IShuffle {
public:
	void logToScreen() const override;
	void logToFile(const std::string& filename) const override;
	double calculate() const;
	void shuffle() const override;
	void shuffle(size_t i, size_t j) const override;
};