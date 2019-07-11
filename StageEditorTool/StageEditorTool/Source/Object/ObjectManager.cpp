#include "ObjectManager.h"
#include "../File/File.h"
#include  "../Factory/ObjectFactory.h"
#include "../Object/Parameter/CollisionObjectParameter.h"
#include "../Collision/CollisionDefinition.h"
#include "../Collision/CollisionManager.h"

void ObjectManager::LoadData(const char* file_name) {

	if (File::InputMapData(file_name, m_map_list) == false)
	{
		return;
	}

	AddObject();
}

void ObjectManager::AddObject() {
	
	ObjectFactory factory;
	//マウスオブジェクト作成
	CollisionObjectParameter mouse_param(
		CollisionType::POINT_TYPE,
		"",
		0.f, 0.f
	);
	m_object_list.emplace_back(factory.CreateMaouseObject(mouse_param));

	if (m_map_list.empty()==false) {
		//マップオブジェクト作成	
		for (int i = 0; i < m_map_list.size(); ++i) {
			m_object_list.emplace_back(factory.CreateMapObject(m_map_list[i]));
		}
	}
}

void ObjectManager::Init() {

	
	for (auto obj : m_object_list) {

		if (obj == nullptr) {
			return;
		}
		else if (obj->IsDelete() == true) {
			continue;
		}
		obj->Init();
	}
}

void ObjectManager::Update() {

	for (auto obj : m_object_list) {

		if (obj == nullptr) {
			return;
		}
		else if (obj->IsDelete() == true) {
			continue;
		}
		obj->Update();
	}

	CollisionManager::GetInstance()->Update();
}

void ObjectManager::Draw() {

	for (auto obj : m_object_list) {

		if (obj == nullptr) {
			return;
		}
		else if (obj->IsDelete() == true) {
			continue;
		}
		obj->Draw();
	}
}