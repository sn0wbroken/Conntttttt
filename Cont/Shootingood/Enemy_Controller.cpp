#include"Enemy_Controller.h"

// コンストラクタ
Enemy_Controller::Enemy_Controller() {
	enemy_AI = std::make_shared<Enemy_AI>();
}

// デストラクタ
Enemy_Controller::~Enemy_Controller() {
}

void Enemy_Controller::Update()
{
	OutputDebugString("Controller Called\n");
	enemy_AI->Update();
}

