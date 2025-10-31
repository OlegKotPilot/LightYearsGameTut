#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: mWindow(sf::VideoMode(720, 900), "Light Years")
	{
		sf::Window window();
	}
	void Application::Run()
	{
		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
					mWindow.close();
			}
		}

	}
}


