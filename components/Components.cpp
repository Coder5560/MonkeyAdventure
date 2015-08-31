#include "Components.h"


PositionComponent::PositionComponent(float x, float y): x(x),y(y){}
PhysicComponent::PhysicComponent(Vec2 velocity, Vec2 acceleration) : velocity(velocity), acceleration(acceleration), friction(0), bounce(0){}
GravityComponent::GravityComponent(float gravity): enable(false), gravity(gravity){}
MapSensorComponent::MapSensorComponent(): onMap(false){}
BoundComponent::BoundComponent(float width, float height) : x1(-width / 2), x2(width / 2), y1(-height / 2), y2(height / 2){}
BoundComponent::BoundComponent(float x1, float x2, float y1, float y2): x1(x1), y1(y1),x2(x2),y2(y2){}
InfoComponent::InfoComponent(float blood, float mana) : blood(blood), mana(mana){}
RenderComponent::RenderComponent(Node* node) : node(node){}
RenderComponent::~RenderComponent(){ 
	node->removeFromParent(); 
	node->release();
}