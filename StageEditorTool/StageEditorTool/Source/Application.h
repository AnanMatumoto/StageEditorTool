#pragma once



class Application {

public:
	static Application* GetInstance() {
		static Application instance;
		return &instance;
	}

	void Init();

	void Update();

};
