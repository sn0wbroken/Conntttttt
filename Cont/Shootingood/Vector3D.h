#pragma once

// ���W�֌W�������N���X(3D)
class Vector3D {
public:
	// �R���X�g���N�^
	Vector3D();
	// �f�X�g���N�^
	~Vector3D();

	// x���W
	float x;
	// y���W
	float y;
	// z���W
	float z;

	// �ړ�
	void Move(float set_x, float set_y, float set_z);
	// �z�u
	void Arrange(float set_x, float set_y, float set_z);
};

