#pragma once
#include "Vector3D.h"

// ��`�N���X
template <typename T>
class Rect {
public:
	//��
	T top;
	//��
	T left;
	//�E
	T right;
	//��
	T bottom;
	// ��
	T width;
	// ����
	T height;
	
	Rect() {}

	// �R���X�g���N�^
	Rect(T aTop, T aLeft, T aRight, T aBottom) {
		top = aTop;
		left = aLeft;
		right = aRight;
		bottom = aBottom;

		width = right - left;
		height = bottom - top;
	}
	// �R�s�[�R���X�g���N�^
	Rect(const Rect<T> &Right) {
		top = Right.top;
		left = Right.left;
		right = Right.right;
		bottom = Right.bottom;
		width = Right.width;
		height = Right.height;
	}

	void Initialize() {
	};

	// �w�肳�ꂽ�_���܂ނ��ǂ����𔻒肷�郁�\�b�h
	inline bool contains(const T x, const T y) const throw()
	{
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
};
