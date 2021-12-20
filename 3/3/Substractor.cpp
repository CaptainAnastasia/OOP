#include "Substractor.h"
#include <fstream>
#include <iostream>

double Substractor::calculate() const {
    double result = operands[0];
    for (int i = 1; i < operands_count; i++) {
        result -= operands[i];
    }
    return result;
}

void Substractor::logToFile(const string& filename) const {
    ofstream fout(filename, ios::app);
    cout << "\n";
    fout << "Substractor:" << endl;

    fout << "[-" << operands_count << "- " << "operands ]" << endl;
    for (size_t i = 0; i < operands_count; i++) {
        if (i == (operands_count - 1)) {
            if (operands[i] >= 0)
                fout << operands[i];
            else
                fout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                fout << operands[i] << " minus ";
            else
                fout << "(" << operands[i] << ")" << " minus ";
        }
    }
    fout << "\n";
    fout << "[-RESULT- " << calculate() << "]";
}

void Substractor::logToScreen() const {
    cout << "\n";
    cout << "Substractor:" << endl;

    cout << "[-" << operands_count << "- " << "operands ]" << endl;
    for (size_t i = 0; i < operands_count; i++) {
        if (i == (operands_count - 1)) {
            if (operands[i] >= 0)
                cout << operands[i];
            else
                cout << "(" << operands[i] << ")";
        }
        else {
            if (operands[i] >= 0)
                cout << operands[i] << " minus ";
            else
                cout << "(" << operands[i] << ")" << " minus ";
        }
    }
    cout << "\n";
    cout << "[-RESULT- " << calculate() << "]";
}
