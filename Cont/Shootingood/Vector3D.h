#pragma once

#include"DxLib.h"
#include<numeric>

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
	// Dxlib��VECTOR���g��(Dxlib�̋@�\�ł��̌^���������̂������׍��킹��)
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

	inline const Vector3D operator*(const float& flt) const
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
	inline operator DxLib::VECTOR() const
	{
		return DxLib::VGet(x, y, z);
	}
#pragma endregion
#pragma region Math
	//�x�N�g�������O�X
	static Vector3D VectorLength(Vector3D vector)
	{
		Vector3D tmp;

		tmp.x = vector.x * vector.x;
		tmp.y = vector.y * vector.y;
		tmp.z = vector.z * vector.z;

		return tmp;
	}
	//�m������
	static double Norm2(double _x, double _y)
	{
		return sqrt(_x * _x + _y * _y);
	}
	//�������v�Z�i�o�r���j�A�l���\�b�h�j
	static double sqrt(double s)
	{
		double tmp_x = s / 2.0; // Is there any better way to determine initial value?
		double last_x = 0.0; // the value one before the last step

		while (tmp_x != last_x) // until the difference is not significant
		{ // apply Babylonian method step
			last_x = tmp_x;
			tmp_x = (tmp_x + s / tmp_x) / 2.0;
		}

		return tmp_x;
	}
	//�x�N�g���̃m�[�}���C�Y
	static Vector3D normalize(Vector3D vector)
	{
		float mag = 1 / Norm2(vector.x, vector.y);
		float _x = vector.x * mag;
		float _y = vector.y * mag;

		return Vector3D(VGet(_x, _y, 0));
	}
	//���όv�Z
	static Vector3D dot(Vector3D vector,Vector3D vector2)
	{
		float a[] = { vector.x,vector.y,vector.z };
		float b[] = { vector2.x,vector2.y,vector2.z };
		//�X�^���_�[�h���C�u�����̓��όv�Z
		std::inner_product(a, a + sizeof(a) / sizeof(a[0]), b, 0);

		return Vector3D();
	}
	//�N���X�όv�Z
	static Vector3D cross(Vector3D vector,Vector3D vector2)
	{
		Vector3D TempVector;
		TempVector.x = vector.y * vector2.z - vector.z * vector2.y;
		TempVector.y = vector.x * vector2.z - vector.z * vector2.x;
		TempVector.z = vector.x * vector2.y - vector.y * vector2.x;

		return TempVector;
	}
#pragma endregion
	// �l���Z�b�g����
	void Set_Vector(float set_x = 0.0f, float set_y = 0.0f, float set_z = 0.0f);
	// �m�����@�x�N�g���̒����v�Z
	void Norm2() const;
};
