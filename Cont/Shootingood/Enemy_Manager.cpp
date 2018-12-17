#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	m_enemy = std::make_shared<std::vector<Enemy>>();
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	//TODO::�G�����Ȃ����Ƃ͂��蓾�Ȃ��Ƃ͎v���̂ŗv��Ȃ���������Ȃ�
	if (m_enemy->empty())
	{
		return;
	}

	enemy_controller->Update();
}

// �G��z�u
void Enemy_Manager::Enemy_Arrange() {
	for (auto enemyitr = m_enemy->begin();; enemyitr++)
	{
		if(enemyitr == m_enemy->end())
		{
			//TODO::�܂��l�����߂Ă��Ȃ����߁A0��}������
			m_enemy->emplace_back(Vector3D(0.0f,0.0f,0.0f));
			break;
		}
		//�g���Ă��Ȃ��G������΍ė��p����B
		if (enemyitr->enemy_status->Is_Dead())
		{
			//TODO::�܂��l�����߂Ă��Ȃ����߁A��@��قǕύX
			enemyitr->Set_Vector3D(Vector3D(0.0f,0.0f,0.0f));
			enemyitr->enemy_status->Initialize_HitPoint();
		}
	}
	if (m_enemy->empty())
	{
		//TODO::�܂��l�����߂Ă��Ȃ����߁A0��}������
		m_enemy->emplace_back(Vector3D(0.0f, 0.0f, 0.0f));
	}
}

// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
