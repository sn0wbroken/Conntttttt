#pragma once

#define _USE_MATH_DEFINES

#include"DxLib.h"
#include"Define_Value.h"

#include<cmath>
#include<memory>

// �v���C���[�̈ړ����Ǘ�����
class Player_Move {
public:
	// �R���X�g���N�^
	Player_Move();
	// �f�X�g���N�^
	~Player_Move();

	// �L�[���͂Ńv���C���[���ړ�������
	void Move();
	// �L�[���͂Ńv���C���[����]������
	void Rotation();

private:
	// �萔���܂Ƃ߂Ă����N���X
	Define_Value define_value;
};
