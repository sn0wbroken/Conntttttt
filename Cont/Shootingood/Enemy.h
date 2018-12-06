#pragma once

#include"DxLib.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<vector>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Character{
public:
	// �R���X�g���N�^
	Enemy();
	// �R�s�[�R���X�g���N�^
	Enemy(float set_x, float set_y);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

private:
	
	// �G�l�~�[�̉摜
	int enemy_graph;
	// �U�����󂯂Ă���Ƃ��̃G�l�~�[�̉摜
	int damage_enemy_graph;
	// �ł��o���e�̑��x
	int bullet_speed;
};
