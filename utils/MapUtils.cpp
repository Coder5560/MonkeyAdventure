#include "MapUtils.h"


MapUtils::MapUtils(){}
MapUtils::~MapUtils(){}

void MapUtils::loadMapFormatch(R::MatchType _type){
	rects.clear();
	map = TMXTiledMap::create("map/test.tmx");
	TMXObjectGroup* group = map->getObjectGroup("map");
	log("groups : %d",group->getObjects().size());
	group->getObject("");
	for (int i = 0; i < group->getObjects().size(); i++){
		ValueMap valueMap = group->getObjects().at(i).asValueMap();
		float x = valueMap.at("x").asFloat();
		float y = valueMap.at("y").asFloat();
		float width = valueMap.at("width").asFloat();
		float height = valueMap.at("height").asFloat();
		rects.push_back(Rect(x,y,width,height));
		log("Object : %f  %f %f %f",x,y,width,height);
	}
}
TMXTiledMap* MapUtils::getMap(){
	return map;
}

bool MapUtils::onMapVertical(float x1, float x2, float y1, float y2){
	

	return false;
}

bool MapUtils::onMapHorizontal(float x1, float x2, float y1, float y2){
	return false;
}

void MapUtils::mapSenser(MapSensorComponent* sensor,BoundComponent* bound,PositionComponent* position,PhysicComponent* physic){
	sensor->onMapDown = sensor->onMapLeft = sensor->onMapRight = sensor->onMapUp = false;
	sensor->_up = sensor->_right = sensor->_left = sensor->_down = 0;
	float time= .015f;
	float x = position->x + physic->velocity.x*time+ bound->x1;
	float y = position->y + physic->velocity.y*time + bound->y1;
	Rect currentRect(position->x, position->y, bound->getWidth(), bound->getHeight());
	Rect nextRect(x, y, bound->getWidth(), bound->getHeight());
	for (Rect rectMap : rects){
	
		if (nextRect.intersectsRect(rectMap)){

			bool collisionX = (currentRect.getMinY() > rectMap.getMaxY()) || (currentRect.getMaxY() > rectMap.getMinY());
			bool collisionY = (currentRect.getMinX() > rectMap.getMaxX()) || (currentRect.getMaxX() > rectMap.getMinX());
			
			sensor->onMapLeft = collisionX && (currentRect.getMinX()>rectMap.getMaxX());
			sensor->onMapRight = collisionX && (currentRect.getMaxX()<rectMap.getMinX());
			sensor->onMapDown = collisionY && (currentRect.getMinY() > rectMap.getMaxY());
			sensor->onMapUp = collisionY && (currentRect.getMaxY() < rectMap.getMinY());

			if (sensor->onMapLeft) sensor->_left = rectMap.getMaxX()+ bound->getWidth()/2 + 1;
			if (sensor->onMapUp) sensor->_up = rectMap.getMinY() - bound->getHeight() / 2 - 1;
			if (sensor->onMapRight) sensor->_right = rectMap.getMinX() - bound->getWidth() / 2 - 1;
			if (sensor->onMapDown) sensor->_down = rectMap.getMaxY() + bound->getHeight() / 2 + 1;
		}
	}
}


