#include "Main.h"

const int SENTINEL = -99;

void UnorderedArrayTest()
{
	UnorderedArray<int> array(3);
	array.push(3);
	array.push(53);
	array.push(83);
	array.push(23);
	array.push(82);
	array[2] = 112;
	array.pop();
	array.remove(2);

	std::cout << "Unordered array contents: ";
	for (int i = 0; i < array.GetSize(); i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
	std::cout << "Search for 53 was found at index: ";
	std::cout << array.search(53);
	std::cout << std::endl;
}

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

void BitArrayTest()
{
	BitArray bitArray(16);
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.SetBit(2);
	bitArray.SetBit(14);
	std::cout << "SetBit: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.SetAllBits();
	std::cout << "SetAllBits: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
	bitArray.ClearAllBits();
	std::cout << "ClearAllBits: " << std::endl;
	std::cout << "Bit 2 = " << bitArray[2] << std::endl;
	std::cout << "Bit 3 = " << bitArray[3] << std::endl;
	std::cout << "Bit 14 = " << bitArray[14] << std::endl;
}

int main()
{
	int input;
	std::cout << "Midterm Practice Programs:\n"
		<< "Unordered Array: 1\n"
		<< "Ordered Array: 2\n"
		<< "Bit Array: 3\n";
	do
	{
		std::cout << "Input test number: ";
		std::cin >> input;
		switch (input)
		{
		case 1:
			UnorderedArrayTest();
			break;

		case 2:
			OrderedArrayTest();
			break;

		case 3:
			BitArrayTest();
			break;

		default:
			std::cout << "Invalid input!" << std::endl << "Type -99 to end" << std::endl;
			break;
		}
	} while (input != SENTINEL);
	return 0;
}