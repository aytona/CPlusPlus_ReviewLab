// C++ Review Lab Exercises
// Class: Data Structures & Algorithms
// By: Christopher Aytona

#include <iostream>
using namespace std;

void Swap(int** x, int** y)
{
	int *temp = *x;
	*x = *y;
	*y = *&temp;
}

int main()
{
	int x = 5, y = 6;
	int *ptr1 = &x, *ptr2 = &y;
	Swap(&ptr1, &ptr2);
	cout << *ptr1 << " " << *ptr2 << endl;	// Prints "6 5"

	return 0;
}
