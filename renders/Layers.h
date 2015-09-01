#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Layers
{
public:
	Layers();
	~Layers();
	static Layers* instance;
	static Layers* getInstance();
	cocos2d::Layer* getBackgroundLayer();
	cocos2d::Layer* getGameLayer();
	cocos2d::Layer* getHudLayer();


	void registerBackgroundNode(Node* node);
	void registerGameNode(Node* node);
	void registerHudNode(Node* node);

	cocos2d::Layer* backgroundLayer;
	cocos2d::Layer* gameLayer;
	cocos2d::Layer* hudLayer;



};

