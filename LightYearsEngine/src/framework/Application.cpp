#include <iostream>
#include "framework/Application.h"

namespace ly
{
	Application::Application()
		: mWindow{ sf::VideoMode{720, 900}, "My_Window" },
		mTargetFrameRate{ 60.f },
		mTickClock{}
	{

	}

	void Application::Run()
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
			std::cout << "Ticking at framerate: " << 1.f / frameDeltaTime << "fps." << std::endl;
		}
	}

	void Application::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void Application::Tick(float deltaTime)
	{
		
	}

	void Application::Render()
	{
		mWindow.clear();

		RenderInternal();
		
		mWindow.display();
	}

	void Application::RenderInternal()
	{
		sf::CircleShape rect{ 50 };
		rect.setFillColor(sf::Color::Green);
		rect.setOrigin(50, 50);
		rect.setPosition(mWindow.getSize().x / 2.f, mWindow.getSize().y / 2.f);

		mWindow.draw(rect);
	}
}