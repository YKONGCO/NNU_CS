#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
class Vector;
using namespace std;

class Matrix
{

public:
	int* m;
	int szl, szr;

	Vector multiply1(Matrix& m, Vector& v);

	Vector& multiply11(Vector& v);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix()
	{
		cout << "~Matrix" << endl;
		if (m)
			delete[] m;
	}
	Matrix& operator=(const Matrix&);

	int sizeL();
	int sizeR();
	int& elem(int, int);
};

#endif