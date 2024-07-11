#ifndef VECTOR_H//作用：防止graphics.h被重复引用
#define VECTOR_H

#include<iostream>
using namespace std;
class Vector
{
public:
	int* v;             			//指向一个数组,表示向量
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