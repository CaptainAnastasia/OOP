#include <iostream>
#include "Matrix.h"
//класс Matrix 

using namespace std;

Matrix::Matrix(int h, int w)
{
	width = w;
	height = h;
	a = new double* [h];
	for (int i = 0; i < h; ++i)
	{
		a[i] = new double[w];
	}
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			a[i][j] = 0;
		}
	}
}

Matrix::Matrix(const Matrix& mat)
{
	width = mat.width;
	height = mat.height;
	a = new double* [height];
	for (int i = 0; i < height; ++i)
	{
		a[i] = new double[width];
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			a[i][j] = mat.a[i][j];
		}
	}
}

Matrix& Matrix::operator++(int d)
{
	Matrix temp = *this;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			a[i][j]++;
		}
	}
	return temp;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			a[i][j]++;
		}
	}
	return *this;
}

Matrix& Matrix::operator--(int d)
{
	Matrix temp = *this;
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			a[i][j]--;
		}
	}
	return temp;
}

Matrix& Matrix::operator--()
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			a[i][j]--;
		}
	}
	return *this;
}

double Matrix::at(int i, int j)
{
	return a[i][j];
}

void Matrix::setAt(int i, int j, double val)
{
	a[i][j] = val;
}
