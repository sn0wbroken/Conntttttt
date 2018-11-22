#include "Enemy_Manager.h"

#include<iterator>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_AI = std::make_shared<Enemy_AI>();
	enemy_status = std::make_shared<Enemy_Status>();

	// 配置
	Enemy_Arrange();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	enemy_AI->Update();
}

// 敵を配置
void Enemy_Manager::Enemy_Arrange() {
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(200, 200);
	enemy->Actor::Add_Child(enemy);
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
