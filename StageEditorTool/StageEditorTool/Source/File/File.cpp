#include "File.h"
#include <fstream>

namespace File {


	bool InputResourceData(
		const char* file_name,
		std::vector<CollisionObjectParameter>&list
	) {
		FILE* file;
		char buf[256];

		fopen_s(&file, file_name, "r");
		if (file == nullptr) {
			return false;
		}

		int read_line  = 0;
		char sprite_name[128];
		CollisionObjectParameter param;

		while (fgets(buf,256,file)!=nullptr)
		{
			if (++read_line == 0) {
				continue;
			}
			else if (read_line > 3) {
				break;
			}


			fscanf_s(file,
				"%d, %d, %[^,], %f,%f,%f, %f,%f,%f",
				&param.object_type,
				&param.collision_type,
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
		int read_line=0;

		fopen_s(&file, file_name, "r");
		if (file == nullptr) {
			return false;
		}

		char sprite_name_[128];
		SpriteObjectParameter param;
		while (fgets(buf, 256, file) != nullptr) {

			if (++read_line == 0) {
				continue;
			}
			if (read_line >3) {
				break;
			}

			fscanf_s(file,
				" %[^,], %f, %f, %f, %f, %f, %f",
				sprite_name_,128,
				&param.pos.x,
				&param.pos.y,
				&param.pos.z,
				&param.rot,
				&param.scale_x,
				&param.scale_y);

			param.sprite_name = sprite_name_;
			list.push_back(param);
		}
		fclose(file);
		return true;
	}

}