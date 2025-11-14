#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode{720, 900}, "My_Window" }
	{

	}

	void Application::Run()
	{
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
		}
	}
}