#include"Enemy_Controller.h"

// �R���X�g���N�^
Enemy_Controller::Enemy_Controller() {
	enemy_AI = std::make_shared<Enemy_AI>();
}

// �f�X�g���N�^
Enemy_Controller::~Enemy_Controller() {
}

void Enemy_Controller::Update()
{
	enemy_AI->Update();
}

