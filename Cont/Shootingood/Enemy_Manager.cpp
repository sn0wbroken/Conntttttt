#include"Enemy_Manager.h"
#include<sstream>

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	//�G�����Ȃ����Ƃ͂��蓾�Ȃ��Ƃ͎v���̂ŗv��Ȃ���������Ȃ�
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

// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Ded() {
	if (active_enemies.empty())
	{
		return true;
	}
	return false;
}
