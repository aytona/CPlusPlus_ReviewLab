#include "Main.h"

void SinglyLinkedListTest()
{
	LinkList<int> lList;
	lList.Push(101);
	lList.Push(201);
	lList.Push(301);
	lList.Push(401);
	lList.Push(501);
	lList.Pop();
	lList.Push(601);
	LinkIterator<int> it;
	std::cout << "Contents of the link list: ";
	for (it = lList.Begin(); it != lList.End(); it++)
		std::cout << " " << *it;
	std::cout << "." << std::endl;
}