#pragma once

#include"Actor.h"
#include"Vector3D.h"

#include<memory>

// ��`�N���X
class Rect {
public:
	// �R���X�g���N�^
	Rect() {};

	// �L�����N�^�[�̓����蔻��p�̔�������ĕԂ�
	std::list<Rect> Make_3DBox(std::shared_ptr<Actor> actor);

	// �ʂ̒��S���W��Ԃ�
	Vector3D Get_Centor_Point(float width, float height, float depth, Vector3D top_right);

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

	// ��
	float width;
	// ����
	float height;

	/*// �w�肳�ꂽ�_���܂ނ��ǂ����𔻒肷�郁�\�b�h
	inline bool contains(const float x, const float y) const throw() {
		return x >= left && x < right && y >= top && y < bottom;
	}
	inline bool contains(const Vector3D point) const throw()
	{
		return contains(point.x, point.y);
	}

	//�����蔻�� �l�p �N���X�n��
	bool Intersects(const Rect<T> &right) {
		return left < right.right &&
			top < right.bottom &&
			right.top < bottom &&
			right.left < this->right;
	}
	//�����蔻�� �l�p �w��o�[�W����
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
	*/
};
