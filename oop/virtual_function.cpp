#include <cassert>
#include <cmath>
#include <iostream>

#define PI 3.14159

class Shape {
public:
	virtual float Area() const = 0;
	virtual float Perimeter() const = 0;
};

class Rectangle : Shape{
public:
	Rectangle(float width, float height) {
		if(width < 0 || height < 0)
			throw std::invalid_argument("Dimension can't be negative.");
		width_ = width;
		height_ = height;
	}

	float Area() const { return width_ * height_; }
	float Perimeter() const { return 2 * (width_ + height_); }
private:
	float width_{};
	float height_{};
};

class Circle: Shape{
public:
	Circle(float radius) {
		if(radius < 0)
			throw std::invalid_argument("Dimension can't be negative.");
		radius_ = radius;
	}

	float Area() const { return PI * radius_ * radius_; }
	float Perimeter() const { return 2 * PI * radius_; }
private:
	float radius_{};
};

int main() {
	double epsilon = 0.1; // useful for floating point equality

    // Test circle
    Circle circle(12.31);
    assert(abs(circle.Perimeter() - 77.35) < epsilon);
    assert(abs(circle.Area() - 476.06) < epsilon);
	std::cout << "Circle area: " << circle.Area() << "\n";

    // Test rectangle
    Rectangle rectangle(10, 6);
    assert(rectangle.Perimeter() == 32);
    assert(rectangle.Area() == 60);
	std::cout << "Rectangle area: " << rectangle.Area() << "\n";
}
