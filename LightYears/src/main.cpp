#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main() {
	//allowcating on the heap to avoid stack overflow issues
	ly::Application* app = new ly::Application();
	app->Run();

	return 0;
}