#include "ObjectFactory.h"
#include "../Object/MapObject.h"
#include "../Object/CollisionObject.h"
#include "../Object/MouseObject.h"

Object* ObjectFactory::CreteSprite(SpriteObjectParameter& param) {

	Object* obj = new SpriteObject(param);
	return obj;
}

Object* ObjectFactory::CreateMapObject(MapObjectParameter& param) {

	Object* obj = new MapObject(param);
	return obj;
}

Object* ObjectFactory::CreateMaouseObject(CollisionObjectParameter& param){

	Object* obj = new MouseObject(param);
	return obj;
}
