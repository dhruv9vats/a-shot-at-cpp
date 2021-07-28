#include <iostream>

#define PI 3.14159

class LineSegment {
public:
	LineSegment(float len) : length(len) {}
	float GetLength() const { return length; }
private:	
	float length{};
};

class Circle {
public:
	Circle(float r) : radius(r) { area = radius.GetLength() * radius.GetLength() * PI; }
	float GetRadius() const { return radius.GetLength(); }
	float GetArea() const { return area; }
private:
	LineSegment radius;
	float area{};
};

int main() {
	Circle circle{7.2};
	std::cout << "The area of a circle with radius " << circle.GetRadius() << " units is " << circle.GetArea() << " units squared\n";
}
