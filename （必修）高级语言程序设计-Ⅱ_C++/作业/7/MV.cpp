#include <iostream>
#include <fstream>
#include <ctime>
#include "Matrix.h"
#include "Vector.h"
using namespace std;

Vector& multiply(Matrix& m, Vector& v)  	//矩阵乘向量
{
	if (m.sizeR() != v.size())
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r(m.sizeL());
	for (int i = 0; i < m.sizeL(); i++)
	{
		r[i] = 0;
		for (int j = 0; j < m.sizeR(); j++)
			r[i] += m.elem(i, j) * v[j];
	}
	return r;
}

Vector& multiply1(Matrix& m, Vector& v)	//矩阵乘向量
{
	if (m.szr != v.sz)
	{
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	Vector r(m.sizeL());
	for (int i = 0; i < m.szl; i++)
	{
		r[i] = 0;
		for (int j = 0; j < m.szr; j++)
			r[i] += m.m[i * m.szr + j] * v.v[j];
	}
	return r;
}

int main()
{
	ifstream in("in.txt");
	if (!in)
	{
		cout << "Can't open the file!" << endl;
		exit(0);
	}
	int x, y;
	in >> x >> y;
	Matrix ma(x, y);
	for (int i = 0; i < x; ++i)
		for (int j = 0; j < y; ++j)
			in >> ma.elem(i, j);
	in >> x;
	Vector ve(x);
	for (int i = 0; i < x; ++i)
		in >> ve[i];
	Vector vx1(ma.sizeL());
	double t_start = clock();
	for (int i = 0; i < 1; i++)
		vx1 = multiply(ma, ve);
	cout << clock() - t_start << endl;
	vx1.display();

	Vector vx2(ma.sizeL());
	t_start = clock();
	for (int i = 0; i < 100; i++)
		vx2 = multiply1(ma, ve);
	cout << clock() - t_start << endl;
	vx2.display();

	Vector vx3(ma.sizeL());
	t_start = clock();
	for (int i = 0; i < 100; i++)
		vx3 = ma.multiply11(ve);
	cout << clock() - t_start << endl;
	vx3.display();

	return 0;
}

