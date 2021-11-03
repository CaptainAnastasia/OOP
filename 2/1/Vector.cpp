#include <iostream>
#include "Vector.h"

//класс Vector
Vector::Vector(int n)
{
	size = n;
	a = new double[n];
	for (int i = 0; i < size; ++i)
	{
		a[i] = 0;
	}
}

Vector::Vector(double* arr, int n)
{
	size = n;
	a = new double[size];
	for (int i = 0; i < size; ++i)
	{
		a[i] = arr[i];
	}
}

Vector::Vector(const Vector& vec)
{
	this->size = vec.size;
	this->a = new double[vec.size];
	for (int i = 0; i < vec.size; ++i)
	{
		this->a[i] = vec.a[i];
	}
}
Vector& Vector::operator++(int d)
{
	Vector temp = *this;
	for (int i = 0; i < size; ++i)
	{
		this->a[i]++;
	}
	return temp;
}

Vector& Vector::operator++()
{
	for (int i = 0; i < size; ++i)
	{
		this->a[i]++;
	}
	return *this;
}

Vector& Vector::operator--(int d)
{
	Vector temp = *this;
	for (int i = 0; i < size; ++i)
	{
		this->a[i]--;
	}
	return temp;
}

 Vector& Vector::operator--()
{
	for (int i = 0; i < size; ++i)
	{
		this->a[i]--;
	}
	return *this;
}

 double& Vector::Vector::operator[](int x)
{
	return this->a[x];
}



Vector::~Vector()
{
	if (a != nullptr)
	{
		delete[] a;
		size = 0;
	}
}
