#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	enemy_controller = std::make_shared<Enemy_Controller>();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	enemy_controller->Update();
}

// �G��z�u
void Enemy_Manager::Enemy_Arrange(Vector3D set_vector3d, float set_degree) {
	//TEST
	position.x = set_vector3d.x;
	position.y = set_vector3d.y;
	position.z = set_vector3d.z;
	enemies.push_back(std::make_shared<Enemy>(position, set_degree));
}

// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
