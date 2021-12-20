#pragma once
#include "ExpressionEvaluator.h"
#include <string>

class Substractor : public ExpressionEvaluator {
public:
    double calculate() const override;
    void logToFile(const string& filename) const override;
    void logToScreen() const override;
};