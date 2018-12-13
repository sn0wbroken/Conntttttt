#include"Enemy_Manager.h"

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {
	enemy_AI = std::make_shared<Enemy_AI>();
	enemy_status = std::make_shared<Enemy_Status>();

	// �z�u
	Enemy_Arrange();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	enemy_AI->Update();
}

// �G��z�u
void Enemy_Manager::Enemy_Arrange() {
	position.x = 0;
	position.y = 0;
	position.z = 0;
	std::shared_ptr<Enemy> enemy = std::make_shared<Enemy>(position);
}

// �G���S�ł��Ă��邩��Ԃ��B�S�ł�true
bool Enemy_Manager::Is_Enemy_All_Ded() {
	return false;
}
