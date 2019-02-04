#pragma once

#include"Enemy_Controller.h"
#include"Enemy.h"
#include"Enemy_AI.h"
#include"Enemy_Status.h"
#include"Define_Value.h"
#include"Unique_Component.h"

#include<memory>
#include<vector>

// �G�l�~�[�̃}�l�[�W���[�N���X(�G�l�~�[�̏��(�e�N���X)��m���Ă���)
class Enemy_Manager : public Unique_Component<Enemy_Manager> {
public:
	//�G�l�~�[�̃R���g���[���[ �������瓮���𐧌䂷��
	std::shared_ptr<Enemy_Controller> enemy_controller;
	std::list<std::shared_ptr<Enemy>> active_enemies;
	std::list<std::shared_ptr<Enemy>> inactive_enemies;

	// ���t���[���Ă΂��
	void Update();

	// �G�l�~�[���S�ł������ǂ���
	bool Is_Enemy_All_Dead();

	// �f�X�g���N�^
	~Enemy_Manager() {}

	// ���W
	Vector3D position;

private:
	// �R���X�g���N�^
	Enemy_Manager();

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �����Ɏ��g���w�肵�����̂����ɐ�������邷
	friend class Unique_Component<Enemy_Manager>;
};
