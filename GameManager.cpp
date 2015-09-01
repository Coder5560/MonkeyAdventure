#include "GameManager.h"

GameManager* GameManager::instance = NULL;
GameManager::GameManager(): _STEP(0.015f),_accumulate(0), _ignoreWorld(false){Director::getInstance()->getScheduler()->scheduleUpdate(this, 0, false);}
GameManager::~GameManager(){}
GameManager* GameManager::getInstance(){
	if (instance == NULL){
		instance = new GameManager();
	}
	return instance;
}
void GameManager::setSystem(artemis::EntitySystem* system){
	_world->getSystemManager()->setSystem(system);
}
void GameManager::createMatch(R::MatchType match){
	_match = match;

	mapUtils = new MapUtils();
	mapUtils->loadMapFormatch(match);
	Layers::getInstance()->registerBackgroundNode(mapUtils->getMap());

	_world = new artemis::World();
	
	// set systems here. be carefully.
	setSystem(new PhysicSystem());
	setSystem(new GravitySystem());
	setSystem(new AccelerationSystem());
	setSystem(new MapSensorSystem());
	setSystem(new AfterPhysicSystem());
	setSystem(new RenderSystem());

	_world->getSystemManager()->initializeAll();

	createTestEntity(200,200,40,40);
	// create MainCharacter and other entities
	
}
void GameManager::createTestEntity(float x, float y, float width, float height){
	Node* node = Node::create();
	Sprite* sprite = Sprite::create("textures/ball.png");
	node->addChild(sprite);
	Layers::getInstance()->registerGameNode(node);
	artemis::Entity &e = _world->createEntity();
	e.addComponent(new PositionComponent(x, y));
	e.addComponent(new RenderComponent(node));
	e.addComponent(new GravityComponent(-9.8f));
	e.addComponent(new MapSensorComponent());
	e.addComponent(new PhysicComponent(Vec2(0,0)));
	e.addComponent(new BoundComponent(width,height));
	e.refresh();
}

void GameManager::update(float delta){
	if (_world == nullptr) return;
	if (_ignoreWorld) return;
	_accumulate += delta;
	while (_accumulate > _STEP){
		_world->setDelta(_STEP);
		_world->loopStart();
		_world->processWorld();
		_accumulate -= _STEP;
	}
}
void GameManager::pauseGame(){

}
void GameManager::resumeGame(){

}

R::MatchType GameManager::getCurrentMatch(){
	return _match;
}
artemis::World* GameManager::getWorld(){
	return _world;
}






