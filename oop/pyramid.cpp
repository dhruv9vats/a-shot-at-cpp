#include <cassert>
#include <iostream>
#include <cmath>

class Pyramid
{
public:
    Pyramid(int length, int width, int height);

    // accessors
    int Length() const;
    int Width() const;
    int Height() const;

    // mutators
    void Length(int length);
    void Width(int width);
    void Height(int height);

    float Volume() const;
    float SurfaceArea() const;

private:
    int length_{1};
    int width_{1};
    int height_{1};
};

Pyramid::Pyramid(int length, int width, int height)
{
    Length(length);
    Width(width);
    Height(height);
}

int Pyramid::Length() const { return length_; }
int Pyramid::Width() const { return width_; }
int Pyramid::Height() const { return height_; }

void Pyramid::Length(int length)
{
    try
    {
        if (length < 0)
            throw length;
    }
    catch (int length)
    {
        std::cout << "Integer should be greater than zero, found: " << length;
        return;
    }

    length_ = length;
}

void Pyramid::Width(int width)
{
    try
    {
        if (width < 0)
            throw width;
    }
    catch (int width)
    {
        std::cout << "Integer should be greater than zero, found: " << width;
        return;
    }

    width_ = width;
}

void Pyramid::Height(int height)
{
    try
    {
        if (height < 0)
            throw height;
    }
    catch (int height)
    {
        std::cout << "Integer should be greater than zero, found: " << height;
        return;
    }

    height_ = height;
}

float Pyramid::Volume() const
{
    return Length() * Width() * Height() / 3;
}

float Pyramid::SurfaceArea() const
{
    return length_ * width_ +
           (length_ * sqrt(pow(width_ / 2, 2) + pow(height_, 2))) +
           (width_ * sqrt(pow(length_ / 2, 2) + pow(height_, 2)));
}

int main()
{
    Pyramid py{2, 3, 4};

    std::cout << "Pyramid Volume: " << py.Volume() << "\n";
    std::cout << "Surface area: " << py.SurfaceArea();

    return 0;
}