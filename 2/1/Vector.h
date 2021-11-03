#pragma once
class Vector
{
public:
	Vector(int n);
	Vector(double* arr, int n);
	Vector(const Vector& vec);
	Vector& operator ++(int d);
	Vector& operator ++();
	Vector& operator --(int d);
	Vector& operator -- ();
	double& operator [](int x);
	//void setAt(int i, double value);
	~Vector();
private:
	int size = 0;
	double* a = nullptr;

};