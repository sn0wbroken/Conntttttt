#pragma once
#include "Vector3D.h"
namespace VMath
{
#pragma region calclator
	//�x�N�^�[�̒���
	Vector3D VectorLength(Vector3D vec);
	// �m�����@�x�N�g���̒����v�Z
	double Norm2(double _x, double _y);
	// �������v�Z �o�r���j�A���\�b�h
	double sqrt(double s);
	//�x�N�g���̐��K��
	Vector3D normalize(Vector3D vector);
	//���όv�Z
	Vector3D dot(Vector3D  vector, Vector3D vector2);
	//�N���X�όv�Z
	Vector3D cross(Vector3D vector,Vector3D vector2);
#pragma endregion
}