#include"Container.h"
#include"Rectangle.h"
#include"Cuboid.h"
#include"Cylinder.h"
#include"Circle.h"
#include<fstream>
#include<sstream>

void Container::addShape(Shape* shape)
{
	container.push_back(shape);
}



void Container::deleteShape(int id)
{
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			delete* it;
			container.erase(it);
			return;
		}
	}
	cout << "Delete error! Not Find with ID!" << endl;
}



void Container::updateShape(int id, Shape* shape)
{
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			delete (*it);
			*it = shape;
			return;
		}
	}
}


Shape* Container::queryShape(int id)
{
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		if ((*it)->getID() == id)
		{
			cout << (*it)->getinfo();
			(*it)->print();
			return *it;
		}
	}
	cerr << "Not find" << endl;
	return nullptr;
}



void Container::serializeShapeToFile(const string& filename)
{
	ofstream outputFile(filename, ios::out);
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		string tmp;
		tmp = (*it)->getShapeinfo() + " " + (*it)->getinfo();
		outputFile << tmp << endl;
	}
	outputFile.close();

}


void Container::printinfo()
{
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		string tmp;
		tmp = (*it)->getShapeinfo() + " " + (*it)->getinfo();
		cout << tmp << endl;
	}
}


void Container::loadShapesFromFile(const string& filename)
{
	ifstream inputFile(filename);  // 替换为你的文件名
	string line;

	if (!inputFile.is_open()) {
		cerr << "Unable to open file for reading." << endl;
		return;
	}

	while (getline(inputFile, line)) {
		int x, y, ID;
		string  Name, type;
		istringstream iss(line);
		iss >> ID >> Name >> x >> y >> type;
		if (type == "Rectangle")
		{
			double w, h;
			iss >> w >> h;
			this->addShape(new Rectangle(w, h, x, y, ID, Name));
		}
		else if (type == "Cylinder")
		{
			double r, height;
			iss >> r >> height;
			this->addShape(new Cylinder(r, height, x, y, ID, Name));
		}
		else if (type == "Circle")
		{
			double r;
			iss >> r;
			this->addShape(new Circle(r, x, y, ID, Name));
		}
		else
		{
			double length, width, height;
			iss >> length >> width >> height;
			this->addShape(new Cuboid(length, width, height, x, y, ID, Name));
		}


	}

	inputFile.close();

	return;



}



Container::~Container()
{
	for (vector<Shape*>::iterator it = container.begin(); it < container.end(); it++)
	{
		delete (*it);
	}
}
