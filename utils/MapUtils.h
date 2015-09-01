#pragma once
#include "cocos2d.h"
#include "utils/R.h"
#include "components/Components.h"
USING_NS_CC;
class MapUtils
{
public:
	MapUtils();
	~MapUtils();
	TMXTiledMap* getMap();
	void loadMapFormatch(R::MatchType _match);
	void mapSenser(MapSensorComponent* mapSensor, BoundComponent* bound,PositionComponent* position,PhysicComponent* physic);
	bool onMapVertical(float x1,float x2, float y1, float y2);
	bool onMapHorizontal(float x1, float x2, float y1, float y2);
	std::vector<Rect> rects;
	TMXTiledMap* map;

};

