#pragma once

#include"Actor.h"

// ����(�U��)��ނ̊��N���X
class Weapon : public Actor {
public:
	// �R���X�g���N�^
	Weapon();
	// �f�X�g���N�^
	~Weapon();

	// �U�����s��
	void Attack();

	// ���W�֌W�̃N���X�B�e���̍��W�Ƃ��Ĉ���
	Vector3D vector3;
};

