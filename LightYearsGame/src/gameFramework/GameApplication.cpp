#include "gameFramework/GameApplication.h"



namespace ly
{
	Application* GetApplication()
	{
		return new GameApplication{};
	}
}