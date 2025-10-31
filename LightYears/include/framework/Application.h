#pragma once
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();
		void Run();
	private:
		void Application::Tick(float DeltaTime);
		void Render();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		float mTargetDeltaTime;
		sf::Clock mTickClock;
	};
}