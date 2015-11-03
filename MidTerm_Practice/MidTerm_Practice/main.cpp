#include "Main.h"

int main()
{
	int input;
	std::cout << "Midterm Practice Programs:\n"
		<< "Unordered Array: 1\n"
		<< "Ordered Array: 2\n"
		<< "Bit Array: 3\n"
		<< "Singly Linked List: 4\n"
		<< "Doubly Linked List: 5\n";
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

		case 4:
			SinglyLinkedListTest();
			break;

		case 5:
			DoublyLinkedListTest();
			break;

		default:
			std::cout << "Invalid input!" << std::endl << "Type -99 to end" << std::endl;
			break;
		}
	} while (input != SENTINEL);
	return 0;
}