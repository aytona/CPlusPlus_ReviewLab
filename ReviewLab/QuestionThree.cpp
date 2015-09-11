// C++ Review Lab Exercises
// Class: Data Structures & Algorithms
// By: Christopher Aytona

#include <iostream>
using namespace std;

void Reverse(int data[], int len)
{
	for (int i = 0; i < len/2; i++)
	{
		int temp = data[len-i-1];
		data[len-i-1] = data[i];
		data[i] = temp;
	}
}

void PrintArray(int data[], int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << data[i];
		if(i != len-1)
			cout << ',';
	}
	cout << endl;
}

int main()
{
	const int len(10);
	int data[len] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout << "Before reverse:" << endl;
	PrintArray(data, len);
	Reverse(data, len);
	cout << "After reverse:" << endl;
	PrintArray(data, len);

	return 0;
}