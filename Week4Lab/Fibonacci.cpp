#include <iostream>
using namespace std;

int FibonacciRecursive(int i)
{
	if (i == 1)
		return 1;
	else if (i == 2)
		return 1;
	else
		return FibonacciRecursive(i - 1) + FibonacciRecursive(i - 2);
}

int FibonacciIterative(int i)
{
	int num1 = 0;
	int num2 = 1;

	if (i == 1)
		return 1;
	else if (i == 2)
		return 1;
	for (int x = 0; x < i; x++)
	{
		num2 = num2 + num1;
		num1 = num2 - num1;
	}
	return num1;
}

int main()
{
	int i;
	cin >> i;
	cout << "Recursive...\t" << FibonacciRecursive(i) << endl;
	cout << "Iterative...\t" << FibonacciIterative(i) << endl;
	return 0;
}