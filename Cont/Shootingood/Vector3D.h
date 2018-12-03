#pragma once

#include "DxLib.h"

// ���W�֌W�������N���X
class Vector3D {
public:
	// �R���X�g���N�^
	Vector3D();
	//�R���X�g���N�^
	Vector3D(float x,float y,float z=0);
	// �R�s�[�R���X�g���N�^
	Vector3D(const Vector3D &vec);
	// �R�s�[�R���X�g���N�^
	Vector3D(const VECTOR &vec);
	// �f�X�g���N�^
	~Vector3D();

	// x���W
	float x;
	// y���W
	float y;
	// z���W
	float z;
	// Dxlib��VECTOR���g��
	VECTOR GetVECTOR();

	// �ړ�
	void Move(float set_x, float set_y, float set_z);
	// �z�u
	void Arrange(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
#pragma region operator
	//�P�̉��Z�q
	inline const Vector3D operator+(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x + vec.x;
		tmp.y = y + vec.y;
		tmp.z = z + vec.z;
		return tmp;
	}

	inline const Vector3D operator-(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x - vec.x;
		tmp.y = y - vec.y;
		tmp.z = z - vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const Vector3D& vec) const
	{
		Vector3D tmp;
		tmp.x = x * vec.x;
		tmp.y = y * vec.y;
		tmp.z = z * vec.z;
		return tmp;
	}

	inline const Vector3D operator*(const float& flt)
	{
		Vector3D tmp;
		tmp.x = x * flt;
		tmp.y = y * flt;
		tmp.z = z * flt;
		return tmp;
	}

	inline const Vector3D operator/(const Vector3D& vec)const
	{
		Vector3D tmp;
		tmp.x = x / vec.x;
		tmp.y = y / vec.y;
		tmp.z = z / vec.z;
		return tmp;
	}
	// ���Z�q+�C�R�[���n
	inline Vector3D operator+=(const Vector3D& vec)
	{
		x += vec.x;
		y += vec.y;
		z += vec.z;
		return *this;
	}
	//DxLib��Vector�ϊ�
	inline operator DxLib::VECTOR() const throw
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion
};
