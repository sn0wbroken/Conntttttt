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
void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, float set_degree) {
	//TEST
	position.x = set_vector3d.x;
	position.y = set_vector3d.y;
	position.z = set_vector3d.z;
	enemies.push_back(std::make_shared<Enemy>(position, set_degree));
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
