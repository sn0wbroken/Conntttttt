#pragma once

#include"Define_Value.h"

// �G�l�~�[��AI���Ǘ�
class Enemy_AI {
public:
	// �R���X�g���N�^
	Enemy_AI();
	// �f�X�g���N�^
	~Enemy_AI();

	// ���t���[������
	void Update();
	// �ړ�
	void Move();
	// �U��
	void Fire();

private:
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �G�l�~�[���E�[����o�悤�Ƃ��ĂȂ���
	bool Is_Over_Max_X(int coordinate_x);
	// �G�l�~�[�����[����o�悤�Ƃ��ĂȂ���
	bool Is_Over_MIn_X(int coordinate_x);

	// �G�l�~�[�̌������e����ʉ��[����o�������
	void Bullet_Over_Max_Y_Erase();

	// ����ƃG�l�~�[�̍U���Ԋu�����čU�����J��o��
	int attack_counter;

	// �J�E���^�[�̏������t���O
	bool is_counter_reset;
};
