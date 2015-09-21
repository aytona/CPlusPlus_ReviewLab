#include <iostream>
using namespace std;

template<typename T>
T min(T val1, T val2)
{
	if (val1 < val2)
		return val1;
	return val2;
}

template<typename T>
T max(T val1, T val2)
{
	if (val1 > val2)
		return val1;
	return val2;
}

template <typename T>
T mid(T area1, T area2, T area3)
{
	T Max = max(area1, max(area2, area3));
	T Min = min(area1, min(area2, area3));
	if (area1 < Max && area1 > Min)
		return area1;
	else if (area2 < Max && area2 > Min)
		return area2;
	else
		return area3;
}

template <typename T>
class Rectangle
{
private:
	T width, height, area;

public:
	T GetWidth() { return width; }
	T GetHeight() { return height; }
	T GetArea()
	{
		area = width * height;
		return area;
	}
	Rectangle(T i, T y)
	{
		width = i;
		height = y;
	}
	void SetArea(T areaValue)
	{
		area = areaValue;
	}
	bool operator < (Rectangle &otherRect)
	{
		return area < otherRect.GetArea();
	}
	bool operator > (Rectangle &otherRect)
	{
		return area > otherRect.GetArea();
	}
};

int main()
{
	double a, b, c, d, e, f;
	cout << "First rectangle width: ";
	cin >> a;
	cout << "First rectangle height: ";
	cin >> b;
	cout << "Second rectangle width: ";
	cin >> c;
	cout << "Second rectangle height: ";
	cin >> d;
	cout << "Third rectangle width: ";
	cin >> e;
	cout << "Third rectangle height: ";
	cin >> f;

	Rectangle<double> r1(a, b);
	Rectangle<double> r2(c, d);
	Rectangle<double> r3(e, f);

	cout << "First Rectangle:\t" << r1.GetWidth() << " Width, " << r1.GetHeight() << " Height, " << r1.GetArea() << " Area" << endl;
	cout << "Second Rectangle:\t" << r2.GetWidth() << " Width, " << r2.GetHeight() << " Height, " << r2.GetArea() << " Area" << endl;
	cout << "Third Rectangle:\t" << r3.GetWidth() << " Width, " << r3.GetHeight() << " Height, " << r3.GetArea() << " Area" << endl;

	Rectangle<double> midRect(mid(r1, r2, r3));

	cout << "Mid Rectangle:\t\t" << midRect.GetWidth() << " Width, " << midRect.GetHeight() << " Height, " << midRect.GetArea() << " Area" << endl;

	return 0;
}