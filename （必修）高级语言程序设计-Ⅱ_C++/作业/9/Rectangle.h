#pragma once
#include "shape.h"
class Rectangle :public Shape
{
public:
	Rectangle(double w, double h, int x1, int y1)
		:width(w), height(h), Shape(x1, y1) {}

	double Area()
	{
		return height * width;
	}
	void print() {
		cout << "width:" << width << endl;
		cout << "height:" << height << endl;
	}

protected:
	double width, height;

};
