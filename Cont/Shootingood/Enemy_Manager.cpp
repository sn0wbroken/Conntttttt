#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	//TODO::�G�����Ȃ����Ƃ͂��蓾�Ȃ��Ƃ͎v���̂ŗv��Ȃ���������Ȃ�
	if (enemies.empty())
	{
		return;
	}
	enemy_controller->Update();
}

// �G��z�u
void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, Vector3D set_playerpos) {
	int i = 0; //itr
	for (auto enemy : enemies) {
		// �z��̒��ŒN������ł��Ȃ������ꍇ�́A�V�����ǉ�����B
		//if (i == (signed int)enemies.size() - 1)
		//{
		//	enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_playerpos));
		//	break;
		//}
		// ����ł���G������΍ė��p����B
		if (enemy->enemy_status->Is_Dead()) {
			enemy->Set_Vector3D(set_vector3d);
			enemy->Set_Radian(set_playerpos);
			enemy->enemy_status->Initialize_HitPoint();
			break;
		}
		i++;
	}

	//���������z��̒�����̏ꍇ������Œǉ�����B
	if (enemies.empty()) {
		enemies.push_back(std::make_shared<Enemy>(set_vector3d, set_playerpos));
	}
	//�ǉ�����@���Ȃ��ƃ��f�����`�悳��Ȃ�
	std::unique_ptr<Actor>& actor = Actor::Get_Instance();
	actor->Add_Child("Enemy" + enemies.size(), enemies.back());
}


// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
