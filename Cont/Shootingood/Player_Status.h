#pragma once

#include"Define_Value.h"

#include<memory>

// �v���C���[�̃X�e�[�^�X�Ƃ��̏������Ǘ�
class Player_Status {
public:
	// �R���X�g���N�^
	Player_Status();
	// �f�X�g���N�^
	~Player_Status();

	// �U�����󂯂���Ă΂��B�̗͂�1���炷
	void Damage();
	// �c�@�����Z�b�g����
	void Reset_Life();

	// �c�@��Ԃ�
	int Get_Life();

	// ����ł��邩��Ԃ�
	bool Get_Is_Dead();

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;

	// �U����(�G��HP - �U���͂Ōv�Z)
	int attack;
	// �ړ����x
	int speed;
	// �c�@
	int life;
};
