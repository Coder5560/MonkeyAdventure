#include "FlashScene.h"

USING_NS_CC;

Scene* FlashScene::createScene()
{
    auto scene = Scene::create();
	auto layer = FlashScene::create();
	scene->addChild(layer);
    return scene;
}

bool FlashScene::init()
{
    if ( !LayerColor::initWithColor(Color4B::WHITE) )
    {
        return false;
    }
	loadedGameData = false;
	goToMenu = false;
	showFlash();
	this->scheduleUpdate();
    return true;
}
void FlashScene::update(float delta){
	if (loadedGameData){
		if (!goToMenu){
			goToMenuScene();
			goToMenu = true;
		}
	}
}
void FlashScene::showFlash(){
	Sprite* flashImage = Sprite::create("splash/Default@2x.png");
	flashImage->ignoreAnchorPointForPosition(false);

	flashImage->setPosition(this->getContentSize() / 2);
	flashImage->setOpacity(0);
	this->addChild(flashImage);

	FadeIn* fadeIn = FadeIn::create(.4f);
	DelayTime* delay = DelayTime::create(.5f);
	FadeOut* fadeOut = FadeOut::create(.2);
	CallFunc* callBack = CallFunc::create([=]() {
		loadGameData();
	});

	Sequence* sequence = Sequence::create(fadeIn, delay, fadeOut, callBack,
		nullptr);
	flashImage->runAction(sequence);
	
}

void FlashScene::loadGameData(){
	loadedGameData = true;
}

void FlashScene::goToMenuScene(){
	auto scene = MenuScene::createScene();
	Director::getInstance()->replaceScene(
	TransitionFade::create(0.3, scene, Color3B(0, 0, 0)));
}

