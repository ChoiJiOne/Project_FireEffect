#include "EntityManager.h"

EntityManager& EntityManager::Get()
{
	static EntityManager instance;
	return instance;
}

void EntityManager::Startup()
{
	CHECK(!bIsStartup_);

	bIsStartup_ = true;
}

void EntityManager::Shutdown()
{
	CHECK(bIsStartup_);

	for (auto& cache : cache_)
	{
		if (cache)
		{
			if (cache->IsInitialized())
			{
				cache->Release();
			}

			cache.reset();
		}
	}

	bIsStartup_ = false;
}

void EntityManager::Destroy(const EntityID& entityID)
{
	CHECK(0 <= entityID && entityID < cacheSize_);

	if (cache_[entityID])
	{
		if (cache_[entityID]->IsInitialized())
		{
			cache_[entityID]->Release();
		}

		cache_[entityID].reset();
	}
}

void EntityManager::Destroy(const IEntity* entity)
{
	EntityID entityID = -1;
	for (uint32_t index = 0; index < cacheSize_; ++index)
	{
		IEntity* cacheEntity = cache_[index].get();
		if (entity == cacheEntity)
		{
			entityID = static_cast<EntityID>(index);
			break;
		}
	}

	if (entityID != -1 && cache_[entityID])
	{
		if (cache_[entityID]->IsInitialized())
		{
			cache_[entityID]->Release();
		}

		cache_[entityID].reset();
	}
}