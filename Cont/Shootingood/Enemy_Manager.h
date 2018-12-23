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
	//�G�l�~�[�̓����𐧌䂷��N���X�Ƃ�����AI
	std::shared_ptr<Enemy_AI> m_enemyAI;
	//�G�l�~�[�̃R���g���[���[�@�������瓮���𐧌䂷��
	std::shared_ptr<Enemy_Controller> enemy_controller;
	// �G�l�~�[�̃X�e�[�^�X�֌W�������N���X
	std::shared_ptr<Enemy_Status> enemy_status;
	//TEST
	std::list<std::shared_ptr<Enemy>> enemies;

	// ���t���[���Ă΂��
	void Update();

	// �G�l�~�[��z�u
	void Enemy_Arrange(Vector3D set_vector3d, float set_degree);

	// �G�l�~�[���S�ł������ǂ���
	bool Is_Enemy_All_Ded();

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
