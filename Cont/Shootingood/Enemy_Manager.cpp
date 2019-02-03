#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	for (auto itr = active_enemies.begin(); itr != active_enemies.end();) {
		if ((*itr)->enemy_status->Is_Dead() || (*itr)->actor_state == eActor_State::Break) {
			(*itr)->actor_state = eActor_State::Break;
			//MV1DeleteModel((*itr)->Get_Model_Handle());
			itr = active_enemies.erase(itr);
		}
		else {
			itr++;
		}
	}
	enemy_controller->Update();
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Dead() {
	if (active_enemies.empty())
	{
		return true;
	}
	return false;
}
