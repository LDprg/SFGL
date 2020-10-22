#pragma once 

#include <SFGL/Core/Types.hpp>

#include <cassert>

#include <queue>
#include <array>

namespace SFGL
{
	/// class EntityManager
	class EntityManager
	{
	public:
		EntityManager()
		{
			// Generate available Entities queue
			for (Entity entity = 0; entity < MAX_ENTITIES; ++entity)
			{
				mAvailableEntities.push(entity);
			}
		}

		/// Create an Entity
		/// @return id of created Entity
		Entity CreateEntity()
		{
			assert(mExistingEntityCount < MAX_ENTITIES && "Entity limit reached! Please set MAX_ENTITIES to a higher value!");

			// Take id from queue
			Entity id = mAvailableEntities.front();
			mAvailableEntities.pop();
			++mExistingEntityCount;

			return id;
		}

		/// Destroy the Entity
		/// @param entity Entity id
		void DestroyEntity(Entity entity)
		{
			assert(entity < MAX_ENTITIES && "Entity out of range!");

			// remove Signature
			mSignatures[entity].reset();

			// add id to queue for reuse
			mAvailableEntities.push(entity);
			--mExistingEntityCount;
		}

		/// Set Signature of an Entity
		/// @param entity Entity id
		/// @param signature new Signature
		void SetSignature(Entity entity, Signature signature)
		{
			assert(entity < MAX_ENTITIES && "Entity out of range!");

			// Add signature to array
			mSignatures[entity] = signature;
		}

		/// Set Signature of an Entity
		/// @param entity Entity id
		/// @return signature Signature of Entity
		Signature SetSignature(Entity entity)
		{
			assert(entity < MAX_ENTITIES && "Entity out of range!");

			// return Entity Signature
			return mSignatures[entity];
		}

	private:
		/// Queue of used Entity IDs
		std::queue<Entity> mAvailableEntities{};

		/// Array of Signatures index is Entity ID
		std::array<Signature, MAX_ENTITIES> mSignatures{};

		/// Count of existing Entities
		std::uint32_t mExistingEntityCount{};
	};
}