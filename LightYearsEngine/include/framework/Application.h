#pragma ones
#include <SFML/Graphics.hpp>

namespace ly
{
	class Application
	{
	public:
		Application();

		void Run();

	private:
		virtual void Tick(float deltaTime);
		void TickInternal(float deltaTime);

		virtual void Render();
		void RenderInternal();

		sf::RenderWindow mWindow;
		float mTargetFrameRate;
		sf::Clock mTickClock;
	};
}