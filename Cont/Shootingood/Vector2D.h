#pragma once

// ���W�֌W�������N���X(2D)
template <typename T>
class Vector2D {
public:
	// �R���X�g���N�^
	Vector2D();
	// �f�X�g���N�^
	~Vector2D();

	// �ړ�
	void Move(T set_x,T set_y);
	// �z�u
	void Arrange(T set_x, T set_y);

	// x���W
	T x;
	// y���W
	T y;
};

