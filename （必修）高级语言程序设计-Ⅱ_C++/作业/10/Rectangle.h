#pragma once
#include"shape.h"
class Rectangle :public Shape
{
protected:
	double width, height;


public:
	Rectangle(double w, double h, int x1, int y1, int ID, string Name)
		:width(w), height(h), Shape(x1, y1, ID, Name) {}

	double Area()
	{
		return height * width;
	}
	void print() {
		cout << "width:" << width << endl;
		cout << "height:" << height << endl;
	}

	string getinfo()
	{
		string text = "Rectangle " + to_string(width) + " "
			+ to_string(height);
		return text;
	}
	~Rectangle() {}
};


