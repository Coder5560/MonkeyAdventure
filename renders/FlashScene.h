#pragma once

#include "cocos2d.h"
#include "renders/MenuScene.h"


class FlashScene : public cocos2d::LayerColor
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
	virtual void update(float delta);
	virtual void showFlash();
	virtual void loadGameData();
	virtual void goToMenuScene();

	bool loadedGameData;
	bool goToMenu;
	CREATE_FUNC(FlashScene);
};


