// C++ Review Lab Exercises
// Class: Data Structures & Algorithms
// By: Christopher Aytona

#include <iostream>
using namespace std;

void Swap(int *n1, int *n2)
{
	int temp = *n1;
	*n1 = *n2;
	*n2 = temp;
}

int main()
{
	int i, y;
	cout << "Input 2 interger values: ";
	cin >> i >> y;
	cout << "\nFirst value: " << i << " Second value: " << y << endl << "Swapping..." << endl;

	Swap(&i, &y);
	cout << "First value: " << i << " Second value: " << y << endl;
	return 0;
}