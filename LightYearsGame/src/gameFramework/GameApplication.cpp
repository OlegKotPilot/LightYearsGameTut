#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
	
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{720, 960, "Light Years", sf::Style::Titlebar | sf::Style::Close}
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy =  newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->SetTexture("C:/Users/OLEGIS/STUDY/UDEMY/LearnCppAndMakeAGameFromScratch04/Projects1/LightYearsGame/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}