#include <iostream>
#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(720, 900), "Light Years" },
		mTargetFrameRate{ 60.0f },
		mTickClock{}
	{
		sf::Window window();
	}
	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.0f;
		float targetDeltaTime = 1.0f / mTargetFrameRate;

		while (mWindow.isOpen())
		{
			sf::Event event;
			while (mWindow.pollEvent(event))
			{
				if (event.type == sf::Event::EventType::Closed)
					mWindow.close();
			}
			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				// Update Logic Here
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}
		}
	}
	void Application::Tick(float deltaTime)
	{
		std::cout << "Tick at frame rate: " << 1.0f / deltaTime << " FPS" << std::endl;
	}

	void Application::Render()
	{
	}
}


