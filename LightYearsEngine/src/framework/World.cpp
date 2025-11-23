#include "framework/World.h"
#include "framework/Core.h"
#include "framework/Actor.h"

namespace ly
{
	World::World(Application* owningApp)
		: mOwningApp{ owningApp },
		mBeganPlay{ false },
		mActors{},
		mPendingActors{}
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
		for (shared<Actor> actor : mPendingActors)
		{
			mActors.push_back(actor);
			actor->BeginPlayInternal();
		}
		mPendingActors.clear();

		for (auto iter = mActors.begin(); iter != mActors.end(); )
		{
			if (iter->get()->IsPendingDestroy())
			{
				iter = mActors.erase(iter);
			}
			else
			{
				iter->get()->Tick(deltaTime);
				++iter;
			}
		}


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