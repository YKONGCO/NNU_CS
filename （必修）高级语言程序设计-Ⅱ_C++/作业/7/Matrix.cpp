#include<iostream>
#include "Matrix.h"
#include "Vector.h"
using namespace std;



Vector& Matrix::multiply11(Vector& v) 	//矩阵乘向量
{
	if (szr != v.size())

	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r(szl);
	for (int i = 0; i < szl; i++)
	{
		r[i] = 0;
		for (int j = 0; j < szr; j++)
			r.v[i] += m[i * szr + j] * v.v[j];
	}
	return r;
}

Matrix::Matrix(int i, int j) //初始化矩阵
{
	cout << "Matrix" << endl;
	szl = i;
	szr = j;
	if (i <= 0 || j <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i * j];
}

Matrix::Matrix(const Matrix& x)
{
	cout << "Copy Matrix" << endl;

	szl = x.szl;
	szr = x.szr;
	m = new int[szl * szr];
	for (int i = 0; i < szl * szr; i++)
	{
		m[i] = x.m[i];
	}

}

Matrix& Matrix::operator=(const Matrix& x)
{
	if (x.szl <= 0 || x.szr <= 0)
	{
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	if (m)
		delete[] m;
	szl = x.szl;
	szr = x.szr;
	m = new int[szl * szr];
	for (int i = 0; i < szl * szr; i++)
		m[i] = x.m[i];
	return *this;

}

int Matrix::sizeL()
{
	return szl;
}
int Matrix::sizeR()
{
	return szr;
}

int& Matrix::elem(int i, int j)   	//引用返回的目的是返回值可以作左值
{
	if (i < 0 || szl <= i || j < 0 || szr <= j)
	{
		cerr << "Matrix index out of range.\n";
		exit(1);
	}
	return m[i * szr + j];
}


