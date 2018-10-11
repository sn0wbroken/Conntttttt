#pragma once
#include <windows.h>

template <typename T> 
class Rectangle{
public:
	//��
	T Top;
	//��
	T Left;
	//�E
	T Right;
	//��
	T Bottom;

	// �R���X�g���N�^
	Rectangle(T aTop, T aLeft,T aRight, T aBottom) {
		Top = aTop;
		Left = aLeft;
		Right = aRight;
		Bottom = aBottom;
	}
	// �R�s�[�R���X�g���N�^
	Rectangle(const Rectangle<T> &right) {
		Top = a1.Top;
		Left = a1.Left;
		Right = a1.Right;
		Bottom = a1.Bottom;
	}
	//�����蔻�� �l�p �N���X�n��
	bool Intersects(const Rectangle<T> &right) {
		return left < right.right && top < right.bottom && right.left < this->right && right.top < bottom;
	}
	//�����蔻�� �l�p �w��o�[�W����
	bool Intersects(T aTop, T aLeft, T aRight, T aBottom) {
		return left < right && top < bottom && left < right && top < bottom;
	}



};