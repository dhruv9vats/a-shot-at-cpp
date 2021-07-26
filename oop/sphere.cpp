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
        return volume_;
    }

    static float Volume(float radius)
    {
        return M_PI * pow(radius, 3) * 4 / 3;
    }

private:
    float radius_;
    float volume_;
    static float const pi_;
    void Validate()
    {
        if (radius_ < 0)
            throw std::invalid_argument("Radius can't be negative");

        volume_ = Volume(radius_);
    }
};

float const Sphere::pi_{3.14159};

int main(void)
{

    std::cout << "Volume with Static method: " << Sphere::Volume(5);

    Sphere sphere(5);
    assert(sphere.GetRadius() == 5);
    assert(abs(sphere.GetVolume() - 523.6) < 1);

    sphere.SetRadius(3);
    assert(sphere.GetRadius() == 3);
    assert(abs(sphere.GetVolume() - 113.1) < 1);

    bool caught{false};
    try
    {
        sphere.SetRadius(-1);
    }
    catch (...)
    {
        caught = true;
    }
    assert(caught);
}