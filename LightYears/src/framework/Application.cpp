#include "framework/Application.h"
#include <iostream>

namespace ly
{ 

	ly::Application::Application()
		: mWindow{ sf::VideoMode(800, 600), "Light Years" },
		mTargetFrameRate{ 60.f },
		mTickClock{}
	{
	
	}

	void ly::Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFrameRate;
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

			float frameDeltaTime = mTickClock.restart().asSeconds();
			accumulatedTime += frameDeltaTime;
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
			std::cout << "ticking at framerate: " << 1.f / frameDeltaTime << std::endl;
		}
	}

	void ly::Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void Application::RenderInternal()
	{
		mWindow.clear();

		Render();

		mWindow.display();
	}

	void Application::Render()
	{
		sf::CircleShape circle(50.f);
		circle.setFillColor(sf::Color::Green);
		circle.setPosition(375.f, 275.f); // Centering the circle in the window

		mWindow.draw(circle);
	}
	void Application::Tick(float deltaTime)
	{

	}
} // namespace ly
	