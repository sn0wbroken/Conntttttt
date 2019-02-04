#include"Enemy_Manager.h"

// コンストラクタ
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
	LoadDivGraph("Resources/Effect/explosion.png",7,7,1,240,240,e_explosionhandle);
}

void Enemy_Manager::PlayEffect()
{
	if (!active_effectList.empty())
	{
		for(auto itr = active_effectList.begin(); itr != active_effectList.end();){
			DrawBillboard3D(itr->pos, 0.5f, 0.5f, 100.0f, 0, e_explosionhandle[itr->effect_sec], TRUE);
			itr->effect_sec++;
			if (itr->effect_sec >= 7)
			{
				itr = active_effectList.erase(itr);
			}
			itr++;
		}
	}
}

// 毎フレーム呼ばれる
void Enemy_Manager::Update() {
	for (auto itr = active_enemies.begin(); itr != active_enemies.end();) {
		if ((*itr)->enemy_status->Is_Dead() || (*itr)->actor_state == eActor_State::Break) {
			active_effectList.emplace_back((*itr)->vector3d,0);
			(*itr)->actor_state = eActor_State::Break;
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

