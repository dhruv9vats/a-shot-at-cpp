#include <iostream>

#define PI 3.14159

class LineSegment {
public:
	float length{};
	LineSegment(float len) : length(len) {}
};

class Circle {
public:
	LineSegment radius;
	float area{};
	Circle(float r) : radius(r) { area = radius.length * radius.length * PI; }
};

int main() {
	Circle circle{7.2};
	std::cout << "The area of a circle with radius " << circle.radius.length << " units is " << circle.area << " units squared\n";
}
