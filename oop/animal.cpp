#include <string>
#include <iostream>

class Animal
{
public:
    std::string color{};
    std::string name{};
    float age{};
    std::string sound{"no"};

    void Sound() const { std::cout << name << " makes " << sound << " sound.\n"; }
};

class Snake : public Animal
{
public:
    float length{};
    Snake(std::string name, std::string color, float age, float length)
    {
        Animal::name = name;
        Animal::color = color;
        Animal::age = age;
        if (length < 0.)
            throw std::invalid_argument("Length of snake can't be negative!?");
        Snake::length = length;

        Animal::sound = "'hissss...'";
    }
};

class Cat : public Animal
{
public:
    float height{};
    Cat(std::string name, std::string color, float age, float height)
    {
        Animal::name = name;
        Animal::color = color;
        Animal::age = age;
        if (height < 0.)
            throw std::invalid_argument("Height of a Cat can't be negative!?");
        Cat::height = height;

        Animal::sound = "'meow..? meow'";
    }
};

int main()
{
    Snake ss{"mamba", "brown", 1.2, 10};
    std::cout << ss.length << "\n";

    Cat c{"cutey", "jet black", 2.4, 1.5};
    std::cout << c.height << "\n";

    ss.Sound();
    c.Sound();
}