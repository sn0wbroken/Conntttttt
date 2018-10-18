#pragma once
#include "DxLib.h"

// ���W�֌W�������N���X
class Vector3D {
public:
	// �R���X�g���N�^
	Vector3D();
	//�R�s�[�R���X�g���N�^
	Vector3D(const Vector3D &vec);
	//�R�s�[�R���X�g���N�^
	Vector3D(const DxLib::VECTOR &vec);
	// �f�X�g���N�^
	~Vector3D();

	// x���W
	float x;
	// y���W
	float y;
	// z���W
	float z;
	//Dxlib��VECTOR���g��
	DxLib::VECTOR GetVECTOR();

	// �ړ�
	void Move(float set_x, float set_y, float set_z);
	// �z�u
	void Arrange(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
};

