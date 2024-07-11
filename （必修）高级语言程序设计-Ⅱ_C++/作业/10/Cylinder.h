#pragma once
#include "shape.h"
class Cylinder :public Shape
{
public:
	Cylinder(double r, double height, int x1, int y1, int ID, string Name) :
		r(r), height(height), Shape(x1, y1, ID, Name) {}

	double Area()
	{
		return 3.14 * r * r * height;
	}
	void print() {
		cout << "radius:" << r << endl;
		cout << "height:" << height << endl;
	}

	string getinfo()
	{
		string text = "Cylinder " + to_string(r) + " "
			+ to_string(height);
		return text;
	}

	~Cylinder() {}

protected:
	double r, height;

};