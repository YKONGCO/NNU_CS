#include<iostream>
#include "Vector.h"
using namespace std;
int main()
{
	int nums[10] = { 10,1,2,3,5,1,4,2,5,5 };
	Vector a(10, nums);
	a.display();
	Vector b;
	b = a;
	b.display();
	int sum;
	sum = a * b;
	printf("%d", sum);

}