#pragma once

#include "../Object/Parameter/CollisionObjectParameter.h"
#include "../Object/Parameter/SpriteObjectParameter.h"
#include "DataDefinition.h"
#include <string>
#include <vector>

namespace File {
	
	enum DataType {
		MAP_DATA,
		SPRITE_DATA
	};

	bool InputResourceData(
		const char* file_name,
		std::vector<CollisionObjectParameter>&list
	);

	bool InputSpriteData(
		const char* file_name,
		std::vector<SpriteObjectParameter>&list
	);

}