#pragma once
#include "cocos2d.h"
#include "artemis/Artemis.h"
#include "utils/R.h"
USING_NS_CC;

class PositionComponent;
class PhysicComponent;
class GravityComponent;
class MapSensorComponent;
class BoundComponent;
class InfoComponent;
class RenderComponent;


class PositionComponent : public artemis::Component{
public:
	PositionComponent(float x, float y);
	float x;
	float y;
};

class PhysicComponent : public artemis::Component{
public:
	PhysicComponent(Vec2 velocity, Vec2 acceleration);
	Vec2 velocity;
	Vec2 acceleration;
	float bounce;
	float friction;
};

class GravityComponent : public artemis::Component{
public :
	GravityComponent(float gravity);
	bool enable;
	float gravity;
};

class MapSensorComponent : public artemis::Component{
public :
	MapSensorComponent();
	bool onMap;
};

class BoundComponent : public artemis::Component{
public :
	BoundComponent(float width, float height);
	BoundComponent(float x1, float x2, float y1, float y2);
	float x1;
	float x2;
	float y1;
	float y2;
	float getMidX();
	float getMidY();
	float getWidth();
	float getHeight();
};

class InfoComponent : public artemis::Component{
public :
	InfoComponent(float blood, float mana);
	float blood;
	float mana;
};

class RenderComponent :public artemis::Component{
public:
	RenderComponent(Node* node);
	~RenderComponent();
	Node* node;
};