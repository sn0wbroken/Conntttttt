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

private:
	// �萔���܂Ƃ߂Ă����\����
	Define_Value define_value;
};
