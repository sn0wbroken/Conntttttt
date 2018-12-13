#pragma once

#include"DxLib.h"
#include"Rect.h"
#include"Bullet.h"
#include"Enemy_Status.h"
#include"Enemy_Controller.h"

#include<map>
#include<vector>
#include<memory>

// �G�l�~�[�{�̂̃N���X
class Enemy : public Enemy_Controller {
public:
	// �R���X�g���N�^
	Enemy();
	// �R�s�[�R���X�g���N�^
	Enemy(Vector3D position);
	// �f�X�g���N�^
	~Enemy();

	// �G�l�~�[�̃X�e�[�^�X�֌W�̃N���X
	std::shared_ptr<Enemy_Status> enemy_status;

	// �킹����(�����蔻��Ɏg�p)
	std::map<std::string, Rect*> rects;
};
