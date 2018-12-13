#pragma once

#include"Vector3D.h"

// ��`�������N���X
class Rectangle {
public:
	// �R���X�g���N�^
	Rectangle();
	// �f�X�g���N�^
	~Rectangle() {};

	// �l�p�`�̍�����̍��W
	Vector3D top_left;
	// �l�p�`�̉E����̍��W
	Vector3D top_right;
	// �l�p�`�̉E�����̍��W
	Vector3D bottom_right;
	// �l�p�`�̍������̍��W
	Vector3D bottom_left;

	// �@���x�N�g���B�����Ƃ̔���Ɏg��
	Vector3D normal_vector;

	// �ʂ̒��S���W��Ԃ�
	Vector3D Get_Centor_Point(float width, float height, Vector3D top_right);

	// ��
	float width;
	// ����
	float height;
};
