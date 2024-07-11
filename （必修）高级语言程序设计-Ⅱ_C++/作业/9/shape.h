#pragma once
#include <iostream>
using namespace std;
class Shape

{

private:
	int x, y;

public:
	Shape(int x1, int y1) :x(x1), y(y1) { }
	virtual double Area() = 0;
	virtual void print() = 0;


};