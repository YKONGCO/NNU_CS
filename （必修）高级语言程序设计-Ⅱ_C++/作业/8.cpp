#include<iostream>

#include<string>

using namespace std;

class Shape

{

private:

	int x, y;

public:

	Shape(int x1, int y1) :x(x1), y(y1) { }

};

class Rectangle :public Shape

{

public:

	Rectangle(double w, double h)

		:width(w), height(h), Shape(0, 0) {}

	double Area()

	{

		return height * width;

	}

protected:

	double width, height;

};



class Circle :public Shape

{

public:

	Circle(double r) :radius(r), Shape(r, r)
	{
	}

	double Area()

	{

		return 3.1415926 * radius * radius;

	}

protected:

	double radius;

};



class Cuboid : protected Rectangle

{

	double z;

public:

	Cuboid(double a, double b, double c) :Rectangle(a, b)

	{

		z = c;

	}

	double Area()

	{
		double s;
		s = 2 * Rectangle::Area() + 2 * (width + height) * z;
		return s;
	}

};



int main()

{

	Cuboid cub1(2, 3, 4);

	Circle cir1(4.0);

	cub1.Area();

	cir1.Area();


	return 0;

}