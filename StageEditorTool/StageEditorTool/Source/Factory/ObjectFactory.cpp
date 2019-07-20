#include "ObjectFactory.h"
#include "../Object/MapObject.h"
#include "../Object/CollisionObject.h"
#include "../Object/MouseObject.h"
#include "../object/ResourceObject.h"
#include "../Object/ObjectManager.h"

Object* ObjectFactory::CreteSprite(SpriteObjectParameter& param) {

	Object* obj = new SpriteObject(param);
	ObjectManager::GetInstance()->AddRegist(obj);
	return obj;
}

Object* ObjectFactory::CreateMapObject(MapObjectParameter& param) {

	Object* obj = new MapObject(param);
	ObjectManager::GetInstance()->AddRegist(obj);
	return obj;
}

Object* ObjectFactory::CreateMaouseObject(CollisionObjectParameter& param){

	Object* obj = new MouseObject(param);
	return obj;
}

CollisionObject* ObjectFactory::CreateResourceObject(CollisionObjectParameter& param) {

	CollisionObject* obj = new ResourceObject(param);
	return obj;
}