#pragma once

#include"Actor.h"

// ����(�U��)��ނ̊��N���X
class Weapon : public Actor {
public:
	// �R���X�g���N�^
	Weapon();
	// �f�X�g���N�^
	~Weapon();

	// ������
	void Initialize() override;

	// �U�����s��
	void Attack();
};
