#include <cassert>
#include <iostream>
#include <stdexcept>

class Point {
public:
	float x;
	float y;
	Point(float x, float y) : x(x), y(y) {}

	Point operator+(const Point& b) {
		if(x == b.x && y == b.y)
			throw std::invalid_argument("Can't add two points on the same location!");
		return Point{x + b.x, y + b.y};
	}
};

int main()
{
    Point p1(-10, 5), p2(-1, 59);
    Point p3 = p1 + p2; // An example call to "operator +";
    assert(p3.x == p1.x + p2.x);
    assert(p3.y == p1.y + p2.y);
	std::cout << "x: " << p3.x << ", y: " << p3.y;
}


