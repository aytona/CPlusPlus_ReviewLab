#ifndef _CIRCLE_H_
#define _CIRCLE_H_

template <typename T>
class Circle
{
private:
	T radius;

public:
	T GetRadius()
	{
		return radius;
	}
	Circle(T i)
	{
		radius = i;
	}
	bool operator < (Circle &target)
	{
		return radius < target.GetRadius();
	}
	bool operator > (Circle &target)
	{
		return radius > target.GetRadius();
	}
	bool operator == (Circle &target)
	{
		return radius == target.GetRadius();
	}
	template <typename T>
	std::ostream& operator<< (std::ostream& out, const Circle<T> &target)
};

#endif