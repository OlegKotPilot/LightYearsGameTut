#include "framework/World.h"
#include "framework/Core.h"

namespace ly
{
	World::World(Application* owningApp)
		: mOwningApp{ owningApp },
		mBeganPlay{ false }
	{
	}

	void World::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}

	void World::BeginPlay()
	{
		LOG("World Began Play");
	}

	void World::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void World::Tick(float deltaTime)
	{
		LOG("World Tick at framerate: %f  fps.", 1.f/deltaTime);
	}

	World::~World()
	{
	}
}