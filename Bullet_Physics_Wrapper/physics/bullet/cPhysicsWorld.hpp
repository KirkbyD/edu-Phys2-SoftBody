#pragma once
#include <physics/interfaces/iPhysicsWorld.h>
#include "btBulletDynamicsCommon.h"
#include <vector>

namespace nPhysics {
	class cPhysicsWorld : public iPhysicsWorld {
	private:
		btDefaultCollisionConfiguration* mCollisionConfiguration;
		btCollisionDispatcher* mDispatcher;
		btBroadphaseInterface* mOverlappingPairCache;
		btSequentialImpulseConstraintSolver* mSolver;
		btDiscreteDynamicsWorld* mDynamicsWorld;

		std::vector<btCollisionShape*> mShapeVector;

	public:
		cPhysicsWorld();
		virtual ~cPhysicsWorld();

		virtual void Update(float dt);
		virtual bool AddComponent(iPhysicsComponent* component);
		virtual bool RemoveComponent(iPhysicsComponent* component);
		virtual void SetGravity(glm::vec3 gravity);
		virtual void SetCollisionListener(iCollisionListener* listener);

		// Inherited via iPhysicsWorld
		virtual void SetWind(glm::vec3 wind) override;
		virtual glm::vec3 GetWind() override;
	};
}