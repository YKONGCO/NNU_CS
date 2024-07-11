#pragma once
#include <iostream>
#include<string>
using namespace std;
class Shape
{
private:
	int x, y, ID;
	string  Name;


public:
	Shape(int x, int y, int id, string name) :x(x), y(y), ID(id), Name(name) { }
	Shape() { x = 0, y = 0; }
	virtual string getinfo() = 0;
	virtual double Area() = 0;
	virtual void print() = 0;
	int getID() { return ID; }
	string getName() { return Name; }
	string getShapeinfo()
	{
		string tmp = to_string(ID) + " " + Name + " " + to_string(x) + " " + to_string(y);
		return tmp;
	}
	virtual ~Shape() {}

};
