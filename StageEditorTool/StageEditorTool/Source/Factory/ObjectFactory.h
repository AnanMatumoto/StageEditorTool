#pragma once
#include "../Object/Object.h"
#include "../Object/Parameter/CreateParameter.h"
#include "../Object/Parameter/MapObjectParameter.h"
#include "../Object/parameter/CollisionObjectParameter.h"

class MapObject;
class CollisionObject;


class ObjectFactory {

public:

	Object* CreteSprite(SpriteObjectParameter& param);

	Object* CreateMapObject(MapObjectParameter& param);

	Object* CreateMaouseObject(CollisionObjectParameter& param);
};

