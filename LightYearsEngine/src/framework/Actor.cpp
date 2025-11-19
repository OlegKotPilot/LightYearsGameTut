#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld{ owningWorld },
		mHasBegunPlay{ false }
	{

	}

	Actor::~Actor()
	{

	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBegunPlay)
		{
			mHasBegunPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor BeginPlay");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor ticking");
	}
}