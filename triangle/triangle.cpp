// triangle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<cmath>
#include <iostream>

using namespace std;

class Triangle
{
public:
	struct Point
	{
		float x, y;
	};

	float area()const
	{
		auto a = sqrt(pow((B.x - A.x), 2) + pow((B.y - A.y), 2));
		auto b = sqrt(pow((C.x - B.x), 2) + pow((C.y - B.y), 2));
		auto c = sqrt(pow((C.x - A.x), 2) + pow((C.y - A.y), 2));
		auto s = (a + b + c) / 2;
		auto area = sqrt(s * (s - a) * (s - b) * (s - c));
		return area;
	}

	Point center()const
	{
		auto x = (A.x + B.x + C.x) / 3;
		auto y = (A.y + B.y + C.y) / 3;
		Point result;
		result.x = x;
		result.y = y;
		return result;
	}

	Triangle(const Point A, const Point B, const Point C)
	{
		this->A = A;
		this->B = B;
		this->C = C;
	}

private:
	Point A, B, C;
};

int main()
{
	const Triangle triangle(Triangle::Point{-3, 2}, Triangle::Point{5, 4}, Triangle::Point{1, -6});
	std::cout << triangle.area() << std::endl;
	const Triangle::Point center = triangle.center();
	std::cout << center.x << " " << center.y << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
