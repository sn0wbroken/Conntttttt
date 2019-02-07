#pragma once
#include<memory>
#include"Enemy_AI.h"
#include"Enemy_Status.h"

// �G�l�~�[�̓����𐧌䂷��
class Enemy_Controller {
public:
	// �G�l�~�[��AI���Ǘ�	
	std::shared_ptr<Enemy_AI> enemy_AI;
	// �R���X�g���N�^
	Enemy_Controller();
	// �f�X�g���N�^
	virtual ~Enemy_Controller();
	//�A�b�v�f�[�g����
	void Update();
};
