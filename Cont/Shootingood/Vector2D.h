#pragma once

// ���W�֌W�������N���X(2D)
class Vector2D {
public:
	// �R���X�g���N�^
	Vector2D();
	// �f�X�g���N�^
	~Vector2D();

	// �ړ�
	void Move(float set_x, float set_y);
	// �z�u
	void Arrange(float set_x, float set_y);

	// x���W
	float x;
	// y���W
	float y;
};

