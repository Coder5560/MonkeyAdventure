#include "Systems.h"

PhysicSystem::PhysicSystem(){ addComponentType<PhysicComponent>(); }
PhysicSystem::~PhysicSystem(){}
void PhysicSystem::initialize(){ physicMapper.init(*world); }
void PhysicSystem::processEntity(artemis::Entity &e){
	PhysicComponent* physic = physicMapper.get(e);



}


GravitySystem::GravitySystem(){ addComponentType<MapSensorComponent>(); addComponentType<GravityComponent>();  addComponentType<PhysicComponent>(); }
GravitySystem::~GravitySystem(){}
void GravitySystem::initialize(){ mapSensorMapper.init(*world); gravityMapper.init(*world); physicMapper.init(*world); }
void GravitySystem::processEntity(artemis::Entity &e){
	PhysicComponent* physic = physicMapper.get(e);
	GravityComponent* gravity = gravityMapper.get(e);
	MapSensorComponent* mapSensor = mapSensorMapper.get(e);
	if (gravity->enable){
		if (!mapSensor->onMapDown){
			physic->velocity.y += gravity->gravityY*world->getDelta();
		}
		physic->velocity.x += gravity->gravityX*world->getDelta();
	}
}


AccelerationSystem::AccelerationSystem(){ addComponentType<AccelerateComponent>();  addComponentType<PhysicComponent>(); }
AccelerationSystem::~AccelerationSystem(){}
void AccelerationSystem::initialize(){ physicMapper.init(*world); accelerateMapper.init(*world); }
void AccelerationSystem::processEntity(artemis::Entity &e){
	AccelerateComponent* accelerate = accelerateMapper.get(e);
	PhysicComponent* physic = physicMapper.get(e);
	physic->velocity.x += accelerate->acceleration.x*world->getDelta();
	physic->velocity.y += accelerate->acceleration.y*world->getDelta();
}



MapSensorSystem::MapSensorSystem(){ addComponentType<MapSensorComponent>();  addComponentType<PhysicComponent>();  addComponentType<PositionComponent>();  addComponentType<BoundComponent>(); }
MapSensorSystem::~MapSensorSystem(){}
void MapSensorSystem::initialize(){ physicMapper.init(*world); mapSensorMapper.init(*world); positionMapper.init(*world); boundMapper.init(*world); }
void MapSensorSystem::processEntity(artemis::Entity &e){
	PhysicComponent* physic = physicMapper.get(e);
	MapSensorComponent* mapSensor = mapSensorMapper.get(e);
	BoundComponent* bound = boundMapper.get(e);
	PositionComponent* position = positionMapper.get(e);
	GameManager::getInstance()->mapUtils->mapSenser(mapSensor, bound, position, physic);
}


AfterPhysicSystem::AfterPhysicSystem(){ addComponentType<PositionComponent>();  addComponentType<PhysicComponent>(); addComponentType<MapSensorComponent>(); }
AfterPhysicSystem::~AfterPhysicSystem(){}
void AfterPhysicSystem::initialize(){ physicMapper.init(*world); positionMapper.init(*world); mapSensorMapper.init(*world); }
void AfterPhysicSystem::processEntity(artemis::Entity &e){
	PositionComponent* position = positionMapper.get(e);
	PhysicComponent* physic = physicMapper.get(e);
	MapSensorComponent* mapSensor = mapSensorMapper.get(e);

	if (mapSensor->onMapLeft) {
		position->x = mapSensor->_left;
		physic->velocity.x = 0;
	}
	if (mapSensor->onMapRight) {
		position->x = mapSensor->_right;
		physic->velocity.x = 0;
	}
	if (mapSensor->onMapUp) {
		position->y = mapSensor->_up;
		if (abs(physic->velocity.y) < 6)
			physic->velocity.y = 0;
		else
			physic->velocity.y *= -.25;

	}
	if (mapSensor->onMapDown) {
		if (abs(physic->velocity.y) < 6){
			physic->velocity.y = 0;
		}
		else
			physic->velocity.y *= -.25;
		position->y = mapSensor->_down;
	}
	{
		position->x += physic->velocity.x*world->getDelta();
		position->y += physic->velocity.y*world->getDelta();
	}
}


RenderSystem::RenderSystem(){ addComponentType<PositionComponent>();  addComponentType<RenderComponent>(); }
RenderSystem::~RenderSystem(){}
void RenderSystem::initialize(){ positionMapper.init(*world); renderMapper.init(*world); }
void RenderSystem::processEntity(artemis::Entity &e){
	PositionComponent* position = positionMapper.get(e);
	RenderComponent* render = renderMapper.get(e);
	if (render->node){
		render->node->setPosition(Vec2(position->x, position->y));
	}
}