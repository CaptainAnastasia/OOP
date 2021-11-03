#pragma once

class Matrix
{
public:
	Matrix(int h, int w);
	Matrix(const Matrix& mat);
	Matrix& operator++(int d);
	Matrix& operator++();
	Matrix& operator --(int d);
	Matrix& operator --();
	double at(int i, int j);
	void setAt(int i, int j, double val);


private:
	int height = 0;
	int width = 0;
	double** a = nullptr;
};