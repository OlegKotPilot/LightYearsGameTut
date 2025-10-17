#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

int main() {
	sf::RenderWindow renderWindow{ sf::VideoMode{100, 100}, "My_Window" };

	std::cout << "Hello, World!" << std::endl;
	return 0;
}