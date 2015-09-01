#pragma once

#include "cocos2d.h"
#include "utils/R.h"
#include "renders/GameScene.h"
#include "renders/Layers.h"

class MenuScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	virtual void update(float deltaTime);
	virtual void goToGame(R::MatchType type);
	CREATE_FUNC(MenuScene);
};


