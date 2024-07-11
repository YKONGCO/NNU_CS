#include "shape.h"

#include "Rectangle.h"

#include "Circle.h"

#include <iostream>

using namespace std;

void main()

{

	Shape* ps[100];
	Rectangle r1(1, 1, 3, 4), r2(2, 2, 3, 5), r3(3, 3, 4, 6);
	Circle c1(2, 3, 4), c2(3, 3, 6), c3(4, 5, 10);

	ps[0] = &r1;

	ps[1] = &r2;

	ps[2] = &c1;

	ps[3] = &r3;

	ps[4] = &c2;

	ps[5] = &c3;

	for (int i = 0; i < 6; i++)

	{

		double s = ps[i]->Area();

		cout << s << endl;;

		ps[i]->print();

	}

}