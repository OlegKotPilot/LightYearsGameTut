#pragma once
#include <SFML/Graphics.hpp>
#include "framework/Core.h"

namespace ly
{
	class World;
	class Application
	{
	public:
		Application(unsigned int windowWidth, unsigned int windowHeight, const std::string& title, sf::Uint32 style);

		void Run();

		template<typename WorldType>
		weak<WorldType> LoadWorld();

	private:
		virtual void Tick(float deltaTime);
		void TickInternal(float deltaTime);

		virtual void Render();
		void RenderInternal();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		float mTargetDeltaTime;
		sf::Clock mTickClock;

		shared<World> currentWorld;
	};


	template<typename WorldType>
	weak<WorldType> Application::LoadWorld()
	{
		shared<WorldType> newWorld{ new WorldType{ this } };
		currentWorld = newWorld;
		currentWorld->BeginPlayInternal();
		return newWorld;
	}
}