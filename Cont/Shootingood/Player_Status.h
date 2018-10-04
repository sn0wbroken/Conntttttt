#pragma once

#include"Player.h"
#include"Define_Value.h"

#include<memory>

// �v���C���[�̃X�e�[�^�X�Ƃ��̏������Ǘ�
class Player_Status {
public:
	// �R���X�g���N�^
	Player_Status();
	// �f�X�g���N�^
	~Player_Status();

	// ���񂾂�Ă΂��B�c�@��1���炷
	void Dead();
	// �c�@�����Z�b�g����
	void Reset_Life();
	// �c�@��Ԃ�
	int Get_Life();

	// �ړ����x��Ԃ�
	int Get_Speed();

private:
	std::shared_ptr<Player> player;

	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;

	// �U����(�G��HP - �U���͂Ōv�Z)
	int attack;
	// �ړ����x
	int speed;
	// �c�@
	int life;
};
