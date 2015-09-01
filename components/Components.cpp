#include "Components.h"


PositionComponent::PositionComponent(float x, float y): x(x),y(y){}
PhysicComponent::PhysicComponent(Vec2 velocity) : velocity(velocity), friction(0), bounce(0){}
AccelerateComponent::AccelerateComponent(Vec2 acceleration) : acceleration(acceleration){}
GravityComponent::GravityComponent(float gravity): enable(true), gravityY(gravity),gravityX(0){}
MapSensorComponent::MapSensorComponent() : onMapUp(false), onMapDown(false), onMapLeft(false), onMapRight(false), _up(0), _down(0), _right(0), _left(0){}
BoundComponent::BoundComponent(float width, float height) : x1(-width / 2), x2(width / 2), y1(-height / 2), y2(height / 2){}
BoundComponent::BoundComponent(float x1, float x2, float y1, float y2): x1(x1), y1(y1),x2(x2),y2(y2){}
float BoundComponent::getWidth(){ return x2 - x1; }
float BoundComponent::getHeight(){ return y2 - y1; }
InfoComponent::InfoComponent(float blood, float mana) : blood(blood), mana(mana){}
RenderComponent::RenderComponent(Node* node) : node(node){}
RenderComponent::~RenderComponent(){ 
	node->removeFromParent(); 
	node->release();
}
