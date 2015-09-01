#pragma once

#include "cocos2d.h"
#include "utils/R.h"
#include "renders/Layers.h"
#include "GameManager.h"

class GameScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene(R::MatchType matchType);
    virtual bool init();
	virtual void update(float delta);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual bool onTouchBegan(Touch* touch,Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	
	void createMatch(R::MatchType match);
	R::MatchType _match;
	CREATE_FUNC(GameScene);
};


