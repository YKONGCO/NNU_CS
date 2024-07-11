#include<iostream>
#include "Vector.h"
#include<math.h>
using namespace std;

Vector::Vector(int s) //�����ռ�
{
	cout << "Vector" << endl;
	sz = s;
	if (s <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
}

Vector::Vector() //�����ռ�
{

	sz = 0;
	v = NULL;
}



Vector::Vector(int s, int* nums) //�����ռ�
{
	sz = s;
	if (s <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
	for (int i = 0; i < s; i++)
	{
		v[i] = nums[i];
	}
}

Vector::Vector(const Vector& x)
{
	cout << "Copy Vector" << endl;
	sz = x.sz;
	v = new int[x.sz];
	for (int i = 0; i < x.sz; i++)
	{
		v[i] = x.v[i];
	}

}

Vector& Vector::operator=(const Vector& x)
{
	if (x.sz <= 0)
	{
		cerr << "bad Vector size.\n";
		exit(1);
	}
	sz = 0;
	if (v)
		delete[] v;
	sz = x.sz;
	v = new int[sz];
	for (int i = 0; i < sz; i++)
		v[i] = x.v[i];
	return *this;
}

void Vector::display()
{
	for (int i = 0; i < sz; i++)
		cout << v[i] << " ";
	cout << "\n";
}

int& Vector::operator[](int i) 		//���÷��ص�Ŀ���Ƿ���ֵ��������ֵ
{
	if (i < 0 || i >= sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	return v[i];
}

int Vector::operator*(const Vector& a)
{
	int tmp = 0;
	if (sz != a.sz)
	{
		cerr << "Vector index out of range.\n";
		exit(1);
	}
	for (int i = 0; i < sz; i++)
	{
		tmp += v[i] * a.v[i];
	}
	return tmp;
}

double Vector::mod()
{
	double tmp = 0;
	int sum = 0;
	for (int i = 0; i < sz; i++)
	{
		sum += v[i];
	}
	tmp = sqrt(sum);
	return tmp;
}