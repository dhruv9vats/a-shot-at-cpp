#include <iostream>

class Human {};

void hello() { std::cout << "Hello, World!\n"; }
void hello(Human human) { std::cout << "Hello, Human!\n"; }

int main() {
	hello();
	hello(Human());
}
