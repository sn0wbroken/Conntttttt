#pragma once

// ���W�֌W�������N���X(3D)
template <typename T>
class Vector3D {
public:
	// �R���X�g���N�^
	Vector3D();
	// �f�X�g���N�^
	~Vector3D();

	// x���W
	T x;
	// y���W
	T y;
	// z���W
	T z;

	// �ړ�
	void Move(T set_x, T set_y, T set_z);
	// �z�u
	void Arrange(T set_x, T set_y, T set_z);
};

