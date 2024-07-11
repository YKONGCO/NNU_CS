#include "Container.h"
#include"Container.h"
#include"Rectangle.h"
#include"Cuboid.h"
#include"Cylinder.h"
#include"Circle.h"
#include <iostream>
#include <vector>

int main() {

	Container shapeContainer;

	shapeContainer.addShape(new Rectangle(10, 5, 3, 3, 1, "A"));
	shapeContainer.addShape(new Circle(3, 0, 3, 2, "B"));
	shapeContainer.addShape(new Cuboid(3, 2, 4, 3, 4, 3, "C"));
	shapeContainer.addShape(new Cylinder(2, 5, 0, 9, 4, "D"));

	// 打印所有图元信息
	cout << "Shapes after adding:" << endl;
	shapeContainer.printinfo();



	// 删除一个图元
	shapeContainer.deleteShape(2);
	cout << "Shapes after deleting:" << endl;
	shapeContainer.printinfo();




	// 更新一个图元
	shapeContainer.updateShape(3, new Circle(3, 0, 0, 3, "UpdatedCircle"));
	cout << "Shapes after updating:" << endl;
	shapeContainer.printinfo();


	// 查询一个图元
	Shape* queriedShape = shapeContainer.queryShape(3);
	if (queriedShape) {
		cout << "Queried Shape Info: " << endl;
		queriedShape->print();
		cout << "Area:" << queriedShape->Area() << endl;
	}

	// 序列化所有图元到文件
	shapeContainer.serializeShapeToFile("shapes.txt");


	// 从文件加载图元
	Container shapeContainer2;
	shapeContainer2.loadShapesFromFile("shapes.txt");

	// 打印加载的图元信息
	cout << "\nShapes after loading from file:" << endl;
	shapeContainer2.printinfo();


	return 0;
}
