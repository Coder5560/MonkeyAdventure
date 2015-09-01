#include "Layers.h"

Layers* Layers::instance = NULL;

Layers::Layers(){
	Size size = Director::getInstance()->getWinSize();

	backgroundLayer = Layer::create();
	backgroundLayer->setContentSize(size);

	gameLayer = Layer::create();
	gameLayer->setContentSize(size);

	hudLayer = Layer::create();
	hudLayer->setContentSize(size);
}
Layers::~Layers(){}

Layers* Layers::getInstance(){
	if (instance == NULL){
		instance = new Layers();
	}
	return instance;
}

Layer* Layers::getBackgroundLayer(){
	return backgroundLayer;
}
Layer* Layers::getGameLayer(){
	return gameLayer;
}
Layer* Layers::getHudLayer(){
	return hudLayer;
}
void Layers::registerBackgroundNode(Node* node){
	backgroundLayer->addChild(node);
	node->setCameraMask((unsigned short)CameraFlag::USER1);
}

void Layers::registerGameNode(Node* node){
	gameLayer->addChild(node);
}
void Layers::registerHudNode(Node* node){
	hudLayer->addChild(node);
	node->setCameraMask((unsigned short)CameraFlag::USER2);
}
