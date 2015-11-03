#include "Main.h"

void OrderedArrayTest()
{
	OrderedArray<int> array(3);
	array.push(43);
	array.push(8);
	array.push(23);
	array.push(94);
	array.push(17);
	array.pop();
	array.remove(2);

	std::cout << "Ordered array contents: ";
	for (int i = 0; i < array.GetSize(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "Search for 12 was found at index: ";
	std::cout << array.search(12) << std::endl;;
}