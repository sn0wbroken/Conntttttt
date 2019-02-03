#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// ���t���[���Ă΂��
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

// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Dead() {
	if (active_enemies.empty())
	{
		return true;
	}
	return false;
}
