#pragma once

#include"Enum.h"
#include"Define_Value.h"

// �G�l�~�[�̃X�e�[�^�X�Ƃ��̏������Ǘ�
class Enemy_Status {
public:
	// �ړ��������
	eMove_Direction move_direction;

	// �R���g���N�^
	Enemy_Status();
	// �R�s�[�R���X�g���N�^
	Enemy_Status(eStage stage);
	// �f�X�g���N�^
	~Enemy_Status();

	// �ړ����x��Ԃ�
	int Get_Speed();
	// U�^�[��������
	void U_Turn();
	// ���݂̗̑͂�Ԃ�
	int Get_Hit_Point();
	// �U���Ԋu��Ԃ�
	int Get_Attack_Span();
	// �e�̑��x��Ԃ�
	int Get_Bullet_Speed();

	// ����ł��邩��Ԃ�
	bool Is_Dead();
	// ����ł��炤�B�U�����󂯂��Ƃ��ɌĂ΂��
	void Dead();
	// �_���[�W��������ɖ߂�
	void Initialize_Is_Damage();
	// �q�b�g�|�C���g�����ɖ߂��B
	void Initialize_IsDead();

private:

	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �ړ����x
	int speed;
	// �̗� 0�Ŏ��S
	int hit_point;
	// �U���̊Ԋu
	int attack_span;
	// �ł��o���e�̑��x
	int bullet_speed;

	// ���S���� true�Ŏ��S
	bool is_dead;
	// �_���[�W����(�_���[�W���󂯂����ǂ���) �_���[�W���󂯂���true
	bool is_damage;
};
