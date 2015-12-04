#include "Main.h"

void ArraybasedStacksTest()
{
	std::cout << "Array based example" << std::endl;
	ArraybasedStack<int> sList(5);
	sList.push(101);
	sList.push(201);
	sList.push(301);
	sList.push(401);
	sList.push(501);
	sList.pop();
	sList.push(601);
	std::cout << "Contents of the stack:";

	while (!sList.isEmpty())
	{
		std::cout << " " << sList.top();
		sList.pop();
	}
	std::cout << std::endl;
}