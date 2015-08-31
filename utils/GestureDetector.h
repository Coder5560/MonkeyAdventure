#pragma once
#include "cocos2d.h"
USING_NS_CC;
class GestureDetector : public cocos2d::Layer
{
public:
	GestureDetector();
	~GestureDetector();
	void update(float delta);

	void touchDown(float x, float y);
	void tap(float x, float y);
	void longPress(float x, float y);
	void fling(float velocityX, float velocityY);
	void pan(float x, float y, float deltaX, float deltaY);
	void panStop(float x, float y);
	void resetAll();
	float _timeTouch;
	float _isTouch;
	float _hasPan;


};

