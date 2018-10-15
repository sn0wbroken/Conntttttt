#pragma once

// ��`�N���X
template <typename T> 
class Rect{
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

	// �R���X�g���N�^
	Rect() {}
	// �R�s�[�R���X�g���N�^
	Rect(int x, int y) {}
	// �R�s�[�R���X�g���N�^
	Rect(T aTop, T aLeft,T aRight, T aBottom) {
		top = aTop;
		left = aLeft;
		right = aRight;
		bottom = aBottom;
	}
	// �R�s�[�R���X�g���N�^
	Rect(const Rect<T> &right) {
		top    = right.top;
		left   = right.left;
		right  = right.right;
		bottom = right.bottom;
	}

	void Initialize() {
		
	};

	//�����蔻�� �l�p �N���X�n��
	bool Intersects(const Rect<T> &right) {
		return left       < right.right &&
			   top        < right.bottom &&
			   right.top  < bottom &&
			   right.left < this->right;
	}
	//�����蔻�� �l�p �w��o�[�W����
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}
};
