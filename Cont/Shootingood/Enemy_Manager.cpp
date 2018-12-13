#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	enemy_controller->Update();
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(position);
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
