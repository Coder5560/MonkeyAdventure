#include "MenuScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
{
    auto scene = Scene::create();
	auto layer = MenuScene::create();
	scene->addChild(layer);
    return scene;
}

bool MenuScene::init()
{
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
	this->scheduleUpdate();
	
	Sprite* bg = Sprite::create("backgrounds/bg8.png");
	bg->setPositionX(500);
	bg->setPositionY(Director::getInstance()->getWinSize().height/2);
	this->addChild(bg);

	ui::ImageView* btnPlay = R::Utils::createImageButton("menu/btn-play.png", [=](){
		goToGame(R::MatchType::MONKEY_RHINO);
	});
	btnPlay->setPosition(Vec2(Director::getInstance()->getWinSize().width - btnPlay->getContentSize().width - 20, 200));
	this->addChild(btnPlay);
    return true;
}


void MenuScene::update(float delta){

}

void MenuScene::goToGame(R::MatchType type){
	auto scene = GameScene::createScene(type);
	Director::getInstance()->replaceScene(TransitionFade::create(0.3, scene, Color3B(0, 0, 0)));
}