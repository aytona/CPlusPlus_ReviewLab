#include "Main.h"

int main()
{
	int input;
	std::cout << "Finals Practice Program:\n"
		<< "Array Based Stacks: 1\n"
		<< "Linked List Stacks: 2\n";
	do
	{
		std::cout << "Input test number: ";
		std::cin >> input;
		switch (input)
		{
		case 1:
			ArraybasedStacksTest();
			break;

		case 2:
			CharacterMatching();
			break;

		default:
			std::cout << "Invalid input!\n"
				<< "Type -99 to end\n";
			break;
		}
	} while (input != SENTINEL);
	return 0;
}