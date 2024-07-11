#pragma once
#include"shape.h"
#include<vector>
class Container
{
	vector<Shape*> container;
public:
	Container(vector<Shape*> a) :container(a) {};
	Container() {};
	void addShape(Shape* shape);
	void deleteShape(int id);
	void updateShape(int id, Shape* shape);
	Shape* queryShape(int id);
	void serializeShapeToFile(const string& filename);
	void printinfo();
	void loadShapesFromFile(const string& filename);
	~Container();


};

