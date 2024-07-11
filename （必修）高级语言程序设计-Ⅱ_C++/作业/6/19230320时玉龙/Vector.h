#ifndef VECTOR_H//���ã���ֹgraphics.h���ظ�����
#define VECTOR_H

#include<iostream>
using namespace std;
class Vector
{
public:
	int* v;             			//ָ��һ������,��ʾ����
	int sz;


	Vector(int);
	Vector(const Vector&);
	Vector(int s, int* nums);
	Vector();
	~Vector()
	{
		delete& sz;
		if (v)
			delete[] v;
	}
	int size()
	{
		return sz;
	}
	Vector& operator=(const Vector&);
	void display();
	int operator*(const Vector& a);
	int& operator[](int);
	double mod();
};

#endif