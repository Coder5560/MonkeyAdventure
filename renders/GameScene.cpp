#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene(R::MatchType type)
{
    auto scene = Scene::create();
	auto game = GameScene::create();
	game->createMatch(type);
	scene->addChild(game);
	return scene;
}

bool GameScene::init()
{
    if ( !LayerColor::initWithColor(Color4B::GRAY) )
    {
        return false;
    }
	this->scheduleUpdate();
	//reateCamera
	auto cameraBackground = Camera::create();
	cameraBackground->setCameraFlag(CameraFlag::USER1);
	this->addChild(cameraBackground);

	auto cameraHud = Camera::create();
	cameraHud->setCameraFlag(CameraFlag::USER2);
	this->addChild(cameraHud);

	this->addChild(Layers::getInstance()->getBackgroundLayer());
	this->addChild(Layers::getInstance()->getGameLayer());
	this->addChild(Layers::getInstance()->getHudLayer());

	this->setKeyboardEnabled(true);
	this->setTouchEnabled(true);
	

	return true;
}


void GameScene::update(float delta){
	GameManager::getInstance()->update(delta);
}
void GameScene::createMatch(R::MatchType type){
	GameManager::getInstance()->createMatch(type);
}




void GameScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event){
	if (keyCode == EventKeyboard::KeyCode::KEY_RIGHT_ARROW){
		auto camera = Camera::getDefaultCamera();
		camera->setPositionX(camera->getPositionX() +10);
	}
	if (keyCode == EventKeyboard::KeyCode::KEY_LEFT_ARROW){
		auto camera = Camera::getDefaultCamera();
		camera->setPositionX(camera->getPositionX() - 10);
	}
}

bool GameScene::onTouchBegan(Touch* touch,Event* event){
	log("touch begin");
	return true;
}
void GameScene::onTouchMoved(Touch* touch, Event* event){
	auto camera = Camera::getDefaultCamera();
	camera->setPositionX(camera->getPositionX()+touch->getDelta().x);
	log("touch moved");
}