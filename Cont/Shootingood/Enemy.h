#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Character.h"
#include"Enemy_Status.h"

#include<map>
#include<vector>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Character{
public:
	// �R���X�g���N�^
	Enemy();
	// �R�s�[�R���X�g���N�^
	Enemy(Vector3D position);
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
	// �킹����(�����蔻��Ɏg�p)
	std::map<std::string, Rect*> rects;
};
