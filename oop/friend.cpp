#include <cassert>
#include <stdexcept>

class Square {
private:
	float side_;
	friend class Rectangle;
public:
	Square(float side) {
		if(side < 0) throw std::invalid_argument("Side can't be less than 0");
		side_ = side;
	}
};

class Rectangle {
private:
	float width_;
	float height_;
public:
	Rectangle(const Square &square) {
		width_ = square.side_;
		height_ = square.side_;
	}

	float Area() const { return width_ * height_; }
};

int main()
{
    Square square(4);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 16);
}
