#pragma once

#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// �G�l�~�[�̃}�l�[�W���[�N���X(�G�l�~�[�̏��(�e�N���X)��m���Ă���)
class Enemy_Manager : public  Unique_Component<Enemy_Manager> {
public:
	// �G�l�~�[�̃X�e�[�^�X�֌W�������N���X
	std::shared_ptr<Enemy_Status> enemy_status;
	// �G�l�~�[��AI���Ǘ�	
	std::shared_ptr<Enemy_AI> enemy_AI;

	// ���t���[���Ă΂��
	void Update();

	// �G�l�~�[��z�u
	void Enemy_Arrange();

	// �G�l�~�[���S�ł������ǂ���
	bool Is_Enemy_All_Ded();

	// �f�X�g���N�^
	~Enemy_Manager() {}

private:
	// �R���X�g���N�^
	Enemy_Manager();

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Enemy_Manager>;
};
