#include "Main.h"

const int SENTINEL = -99;

void UnorderedArrayTest();
void OrderedArrayTest();
void BitArrayTest();
void SinglyLinkedListTest();
void DoublyLinkedListTest();

int main()
{
	int input;
	std::cout << "Midterm Practice Programs:\n"
		<< "Unordered Array: 1\n"
		<< "Ordered Array: 2\n"
		<< "Bit Array: 3\n"
		<< "Singly Linked List: 4"
		<< "Doubly Linked List: 5";
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