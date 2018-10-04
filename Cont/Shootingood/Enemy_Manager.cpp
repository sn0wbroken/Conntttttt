#include "Enemy_Manager.h"

#include<iterator>

// �R���X�g���N�^
Enemy_Manager::Enemy_Manager() {}

// ������
void Enemy_Manager::Initialize() {
	enemy_bullet.clear();

	// �z��̏�����
	enemies.clear();
	// �z�u
	Enemy_Arrange();
}

// ���t���[���Ă΂��
void Enemy_Manager::Update() {
	// �_���[�W�󂯂Ă�����_���[�W��������ɖ߂�
	for (auto& enemy : enemies) {
		auto& enemy_status_ = enemy.enemy_status;
		if (enemy_status_->Is_Damage()) {
			enemy_status_->Initialize_Is_Damage();
		}
	}
	
	enemy_AI->Update();

	// �������e�����X�V
	for(auto& enemy_bullet_ : enemy_bullet){
		enemy_bullet_.Update();
	}
}

// �`��
void Enemy_Manager::Render() {
	for (auto& enemy : enemies) {
		enemy.Render();
	}

	// �������e�����`��
	for (int i = 0; i < enemies.size(); ++i) {
		for (auto& enemy_bullet_ : enemy_bullet) {
			enemy_bullet_.Render();
		}
	}
}

// �G��z�u
void Enemy_Manager::Enemy_Arrange() {
	for (int i = 0; i < define_value.ENEMY_NUMBER; ++i) {
		Arrange(((i % define_value.ENEMY_NUMBER) * define_value.ENEMY_WIDTH), ((define_value.ENEMY_HEIGHT / 2) + ((i % define_value.ENEMY_NUMBER) * define_value.ENEMY_HEIGHT)));
		enemies.emplace_back(Enemy(x, y));
	}

	std::reverse(enemies.begin(), enemies.end());
}

// �G�l�~�[�����̈ʒu�ɔz�u���Ȃ���
void Enemy_Manager::Reset_Enemy() {
	for (auto& enemy : enemies) {
		enemy.Set_X(enemy.Get_Initialize_Position_X());
		enemy.Set_Y(enemy.Get_Initialize_Position_Y());
		enemy_bullet.clear();
	}
}

// �o������G��z�u
void Enemy_Manager::Arrange(int set_x, int set_y) {
	x = set_x;
	y = set_y;
}
