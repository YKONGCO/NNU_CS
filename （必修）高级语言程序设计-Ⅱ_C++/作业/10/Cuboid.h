#pragma once
#include "shape.h"
class Cuboid :public Shape
{
public:
	Cuboid(double length, double width, double height, int x1, int y1, int ID, string Name) :
		length(length), width(width), height(height), Shape(x1, y1, ID, Name) {}

	double Area()
	{
		return length * width * height;
	}
	void print() {
		cout << "length:" << length << endl;
		cout << "width:" << width << endl;
		cout << "height:" << height << endl;
	}

	string getinfo()
	{
		string text = "Cuboid " + to_string(length) + " "
			+ to_string(width) + " "
			+ to_string(height);
		return text;
	}

	~Cuboid() {}



protected:
	double length, width, height;

};