#include "ObjectManager.h"
#include "../File/File.h"
#include  "../Factory/ObjectFactory.h"
#include "../Collision/CollisionDefinition.h"
#include "../Collision/CollisionManager.h"
#include "../Object/ResourceObject.h"

bool ObjectManager::Load(const char* file_name) {

	std::vector<CollisionObjectParameter> data_list;
	//リーソースデータ読み込み
	if (File::InputResourceData(file_name, data_list) == false)
	{
		return false;
	}

	ObjectFactory factory;
	
	CollisionObjectParameter mouse_param(
		ObjectType::MOUSE,
		CollisionType::POINT_TYPE,
		"",
		0.f, 0.f
	);
	//マウスオブジェクト作成
	m_object_list.push_back(factory.CreateMaouseObject(mouse_param));

	if (data_list.empty() == false) {
		//リソースデータ作成	
		for (int i = 0; i < data_list.size(); ++i) {
			m_resource_list.push_back(factory.CreateResourceObject(data_list[i]));
		}
	}
	return true;
}

void ObjectManager::AddRegist(Object* obj) {

	if (obj == nullptr) {
		return;
	}
	m_register_list.push_back(obj);
}

void ObjectManager::AddObject() {

	for (auto obj : m_register_list) {
		if (obj == nullptr) {
			continue;
		}
		m_object_list.push_back(obj);
	}
}

void ObjectManager::Init() {

	for (auto resource : m_resource_list) {
		if (resource == nullptr) {
			continue;
		}
		resource->Init();
	}
}

void ObjectManager::Update() {

	AddObject();
	for (auto resource : m_resource_list) {
		if (resource == nullptr) {
			return;
		}
		resource->Update();
	}

	for (auto obj : m_object_list) {

		if (obj != nullptr) {
			obj->Update();
		}
	}	
}

void ObjectManager::Draw() {

	for (auto resource : m_resource_list) {
		if (resource == nullptr) {
			return;
		}
		resource->Draw();
	}

	for (auto obj : m_object_list) {

		if (obj->IsDelete() == true) {
			continue;
		}
		obj->Draw();
	}
}

void ObjectManager::Delete() {

	for (auto itr = m_object_list.begin(); itr != m_object_list.end();) {
		//オブジェクトが削除モードになっている場合		
		if ((*itr)->IsDelete() == true) {
			Object* obj = *itr;
			if (obj != nullptr) {
				delete obj;
			}
			//配列を削除
			itr = m_object_list.erase(itr);
			continue;
		}
		++itr;
	}
}

void ObjectManager::AllDelete() {

	for (auto obj : m_object_list) {
		if (obj != nullptr) {
			delete obj;
		}
	}
	//リスト内全体の削除
	m_object_list.clear();
}