#include "GestureDetector.h"


GestureDetector::GestureDetector()
{
	resetAll();
	Director::getInstance()->getScheduler()->scheduleUpdate(this,0, false);
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = [=](Touch* touch, Event* event){
		log("touch began");
		resetAll();
		_isTouch = true;
		return true;
	};
	listener->onTouchMoved = [=](Touch* touch, Event* event){
		log("touch moved");


	};
	listener->onTouchCancelled = [=](Touch* touch, Event* event){
		log("touch cancel");
	};
	listener->onTouchEnded = [=](Touch* touch, Event* event){
		log("touch end");
	};

	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener,this);


}
void GestureDetector::resetAll(){
	_timeTouch = 0;
	_isTouch = false;
	_hasPan = false;
}

GestureDetector::~GestureDetector(){}

void GestureDetector::update(float delta){	
}
