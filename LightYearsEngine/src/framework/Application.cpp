#include <iostream>
#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode(720, 900), "Light Years" },
		mTargetFrameRate{ 60.0f },
		mTickClock{}
	{
		//sf::Window window();
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
				TickInternal(targetDeltaTime);
				RenderInternal();
			}
		}
	}
	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
		std::cout << "Tick at frame rate: " << 1.0f / deltaTime << " FPS" << std::endl;
	}

	void Application::Tick(float deltaTime)
	{
	}

	void Application::RenderInternal()
	{
		mWindow.clear();
		Render();

		mWindow.display();
	}
	void Application::Render()
	{
		sf::CircleShape rect{ 100.0f };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50.0f, 50.0f);
		rect.setPosition(mWindow.getSize().x / 2.0f - 50.0f, mWindow.getSize().y / 2.0f);
		mWindow.draw(rect);
	}
}


