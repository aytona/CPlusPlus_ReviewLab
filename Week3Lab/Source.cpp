#include <iostream>
#include "Arrays.h"
#include "Circle.h"
using namespace std;

void TestCircles()
{
	OrderedArray<Circle<int>> array(3);

	array.push(Circle<int>(15));
	array.push(Circle<int>(8));
	array.push(Circle<int>(10));
	cout << "Ordered circles array contents: ";

	for (int i = 0; i < array.GetSize(); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const Circle<T> &target)
{
	out << target.radius;
	return out;
}

int main()
{
	TestCircles();
	return 0;
}
