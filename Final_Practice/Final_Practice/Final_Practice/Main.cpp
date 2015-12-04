#include "Main.h"

int main()
{
	int input;
	std::cout << "Finals Practice Program:\n"
		<< "Stacks: 1\n"
		<< "Queues: 2\n"
		<< "Hash Tables: 3\n"
		<< "Trees: 4\n"
		<< "Advanced Sorting: 5\n"
		<< "Heaps: 6\n"
		<< "Graphs: 7\n";
	do
	{
		std::cout << "Input test number: ";
		std::cin >> input;
		switch (input)
		{
		case 1:
			ArraybasedStacksTest();
			break;

		/*case 2:
			QueuesTest();
			break;

		case 3:
			HashTablesTest();
			break;

		case 4:
			TreesTest();
			break;

		case 5:
			AdvancedSortingTest();
			break;

		case 6:
			HeapsTest();
			break;

		case 7:
			GraphsTest();
			break;*/

		default:
			std::cout << "Invalid input!\n"
				<< "Type -99 to end\n";
			break;
		}
	} while (input != SENTINEL);
	return 0;
}