#include "File.h"
#include <fstream>

namespace File {


	bool InputMapData(
		const char* file_name,
		std::vector<MapObjectParameter>&list
	) {
		FILE* file;
		char buf[256];

		fopen_s(&file, file_name, "r");
		if (file == nullptr) {
			return false;
		}

		int readLine  = 0;
		char sprite_name[128];
		MapObjectParameter param;

		while (fgets(buf,256,file)!=nullptr)
		{
			fscanf_s(file,
				"%d, %[^,], %f,%f,%f, %f,%f,%f",
				&param.type,
				sprite_name,128,
				&param.pos.x,
				&param.pos.y,
				&param.pos.z,
				&param.rot,
				&param.scale_x,
				&param.scale_y
				);
			param.sprite_name = sprite_name;
			list.push_back(param);
		}
		fclose(file);
		return true;
	}

	bool InputSpriteData(
		const char* file_name,
		std::vector<SpriteObjectParameter>&list
	) {
		FILE* file;
		char buf[256];

		fopen_s(&file, file_name, "r");
		if (file == nullptr) {
			return false;
		}

		
		//初めの行の末尾まで移動する
		fseek(file, 0, SEEK_END);
		/*while (fscanf_s(file, buf,
			"%d,%[^,],%f,%f,%f,%f,%f,%f",
			temp.sprite_name,
			temp.pos.x,
			temp.pos.y,
			temp.pos.z,
			temp.scale_x,
			temp.scale_y) != EOF
			)
		{*/
			//list.push_back(temp);
		//}
		fclose(file);
		return true;
	}

}