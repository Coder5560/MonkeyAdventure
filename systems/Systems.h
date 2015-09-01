#pragma once

#include "cocos2d.h"
#include "artemis/Artemis.h"
#include "components/Components.h"
#include "GameManager.h"
USING_NS_CC;

class PhysicSystem;
class GravitySystem;
class AccelerationSystem;
class MapSensorSystem;
class AfterPhysicSystem;
class RenderSystem; 

class PhysicSystem:public artemis::EntityProcessingSystem{
public :
	PhysicSystem();
	~PhysicSystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);
protected:
	artemis::ComponentMapper<PhysicComponent> physicMapper;
};
class GravitySystem :public artemis::EntityProcessingSystem{
public:
	GravitySystem();
	~GravitySystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);
protected:
	artemis::ComponentMapper<MapSensorComponent> mapSensorMapper;
	artemis::ComponentMapper<PhysicComponent> physicMapper;
	artemis::ComponentMapper<GravityComponent> gravityMapper;
};

class AccelerationSystem :public artemis::EntityProcessingSystem{
public:
	AccelerationSystem();
	~AccelerationSystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);
protected:
	artemis::ComponentMapper<PhysicComponent> physicMapper;
	artemis::ComponentMapper<AccelerateComponent> accelerateMapper;
};

class MapSensorSystem :public artemis::EntityProcessingSystem{
public:
	MapSensorSystem();
	~MapSensorSystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);

protected:
	artemis::ComponentMapper<PhysicComponent> physicMapper;
	artemis::ComponentMapper<MapSensorComponent> mapSensorMapper;
	artemis::ComponentMapper<PositionComponent> positionMapper;
	artemis::ComponentMapper<BoundComponent> boundMapper;
};

class AfterPhysicSystem :public artemis::EntityProcessingSystem{
public:
	AfterPhysicSystem();
	~AfterPhysicSystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);
protected :
	artemis::ComponentMapper<PhysicComponent> physicMapper;
	artemis::ComponentMapper<MapSensorComponent> mapSensorMapper;
	artemis::ComponentMapper<PositionComponent> positionMapper;
}; 
class RenderSystem :public artemis::EntityProcessingSystem{
public:
	RenderSystem();
	~RenderSystem();
	virtual void initialize();
	virtual void processEntity(artemis::Entity &e);
protected :
	artemis::ComponentMapper<RenderComponent> renderMapper;
	artemis::ComponentMapper<PositionComponent> positionMapper;
};