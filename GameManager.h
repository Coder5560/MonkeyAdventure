#pragma once
#include "cocos2d.h"
#include "artemis/Artemis.h"
#include "utils/R.h"
#include "utils/MapUtils.h"
#include "systems/Systems.h"
#include "renders/Layers.h"

class GameManager
{
public:
	static GameManager* instance;
	static GameManager* getInstance();
	artemis::World* getWorld();
	void setSystem(artemis::EntitySystem* system);
	virtual void update(float delta);
	void pauseGame();
	void resumeGame();
	void createMatch(R::MatchType type);
	void createTestEntity(float x, float y, float width, float height);
	
	R::MatchType getCurrentMatch();	

	MapUtils* mapUtils;
private :
	GameManager();
	~GameManager();

	const float _STEP;
	float _accumulate;
	bool _ignoreWorld;
	R::MatchType _match;
	artemis::World * _world;
	
};

