#include"Enemy_Manager.h"
#include<sstream>

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	//敵がいないことはあり得ないとは思うので要らないかもしれない
	if (active_enemies.empty())
	{
		return;
	}
	for (auto itr = active_enemies.begin(); itr != active_enemies.end();)
	{
		if ((*itr)->enemy_status->Is_Dead())
		{
			std::stringstream oss;
			oss <<(*itr)->enemy_status->Is_Dead() << std::endl;
			OutputDebugString(oss.str().c_str());
			(*itr)->actor_state = eActor_State::Break;
			inactive_enemies.push_back((*itr));
			itr = active_enemies.erase(itr);
		}
		else
		{
			itr++;
		}
	}
	enemy_controller->Update();
}

// 敵が全滅しているかを返す。全滅でtrue
bool Enemy_Manager::Is_Enemy_All_Ded() {
	if (active_enemies.empty())
	{
		return true;
	}
	return false;
}
