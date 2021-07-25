#include <iostream>
#include <cmath>
#include <cassert>

class Sphere
{
public:
    Sphere(float radius) : radius_(radius)
    {
        Validate();
    }

    float GetRadius() const { return radius_; }
    void SetRadius(float radius)
    {
        radius_ = radius;
        Validate();
    }

    float GetVolume() const
    {
        return M_PI * pow(radius_, 3) * 4 / 3;
    }

private:
    float radius_;
    void Validate() const
    {
        if (radius_ < 0)
            throw std::invalid_argument("Radius can't be negative");
    }
};

int main(void)
{
    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    assert(abs(sphere.GetVolume() - 523.6) < 1);
}