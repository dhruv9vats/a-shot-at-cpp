#include <cassert>
#include <cmath>
#include <iostream>

#define PI 3.1415926535

class VehicleModel {
public:
	virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public VehicleModel {
public:
	void Move(double v, double phi) override {
		theta += phi;
		x += v + cos(theta);
		y += v + sin(theta);
	}

	double x{0};
	double y{0};
	double theta{0};
};

class BicycleModel: public VehicleModel {
public:
	void Move(double v, double phi) override {
		theta += v / L * phi;
		x += v / L + cos(theta);
		y += v / L  + sin(theta);
	}

	double x{0};
	double y{0};
	double theta{0};
	double L{1};
};

int main()
{
    // Test function overriding
    ParticleModel particle;
    BicycleModel bicycle;
    particle.Move(10, PI / 9);
    bicycle.Move(10, PI / 9);
    assert(particle.x != bicycle.x);
    assert(particle.y != bicycle.y);
    assert(particle.theta != bicycle.theta);
}  
