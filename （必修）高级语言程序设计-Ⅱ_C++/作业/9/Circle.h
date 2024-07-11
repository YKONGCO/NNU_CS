#pragma once
#include "shape.h"
class Circle :public Shape
{
public:
	Circle(double r, int x1, int y1) :radius(r), Shape(x1, y1) {}

	double Area()
	{
		return 3.1415926 * radius * radius;
	}
	void print() {
		cout << "radius:" << radius << endl;
	}


protected:
	double radius;

};