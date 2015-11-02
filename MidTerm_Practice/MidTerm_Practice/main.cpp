#include "Arrays.h"
#include <iostream>
using namespace std;

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

	cout << "Unordered array contents: ";
	for (int i = 0; i < array.GetSize(); i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Search for 53 was found at index: ";
	cout << array.search(53);
	cout << endl;
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

	cout << "Ordered array contents: ";
	for (int i = 0; i < array.GetSize(); i++)
		cout << array[i] << " ";
	cout << endl;
	cout << "Search for 12 was found at index: ";
	cout << array.search(12);
	cout << endl;
}

int main()
{
	int input;
	cout << "Midterm Practice Programs:\n"
		<< "Unordered Array: 1\n"
		<< "Ordered Array: 2\n";
	do
	{
		cout << "Input test number: ";
		cin >> input;
		switch (input)
		{
		case 1:
			UnorderedArrayTest();
			break;
			
		case 2:
			OrderedArrayTest();
			break;

		default:
			cout << "Invalid input!" << endl <<  "Type -99 to end" << endl;
			break;
		}
	} while (input != SENTINEL);
	return 0;
}