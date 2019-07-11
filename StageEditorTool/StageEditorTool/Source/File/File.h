#pragma once

#include "../Object/Parameter/MapObjectParameter.h"
#include "../Object/Parameter/SpriteObjectParameter.h"
#include "DataDefinition.h"
#include <string>
#include <vector>

namespace File {
	
	enum DataType {
		MAP_DATA,
		SPRITE_DATA
	};

	bool InputMapData(
		const char* file_name,
		std::vector<MapObjectParameter>&list
	);

	bool InputSpriteData(
		const char* file_name,
		std::vector<SpriteObjectParameter>&list
	);

}