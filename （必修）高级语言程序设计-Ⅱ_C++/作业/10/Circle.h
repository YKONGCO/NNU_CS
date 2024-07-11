#pragma once
#include "shape.h"
class Circle :public Shape
{
public:
	Circle(double r, int x1, int y1, int ID, string Name) :
		radius(r), Shape(x1, y1, ID, Name) {}

	double Area()
	{
		return 3.1415926 * radius * radius;
	}
	void print() {
		cout << "radius:" << radius << endl;
	}

	string getinfo()
	{
		string text = "Circle " + to_string(radius);
		return text;
	}
	~Circle() {}


protected:
	double radius;

};